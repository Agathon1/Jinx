/*
The Jinx library is distributed under the MIT License (MIT)
https://opensource.org/licenses/MIT
See LICENSE.TXT or Jinx.h for license details.
Copyright (c) 2016 James Boer
*/

#pragma once
#ifndef JX_PARSER_H__
#define JX_PARSER_H__


namespace Jinx::Impl
{

	class Parser
	{
	public:
		Parser(RuntimeIPtr runtime, const SymbolList &symbolList, const String & name, std::initializer_list<String> libraries);

		// Convert the symbol list into bytecode
		bool Execute();

		// Retrieve the generated bytecode
		BufferPtr GetBytecode() const { return m_bytecode; }

		// Retrieve a debug-friendly name from an ID.
		String GetNameFromID(RuntimeID id) const;

	private:

		using FunctionPartData = std::vector<std::tuple<FunctionSignaturePartType, size_t, bool>, Allocator<std::tuple<FunctionSignaturePartType, size_t, bool>>>;

		// Structure returned from function finding algorithm
		struct FunctionMatch
		{
			FunctionMatch() : signature(nullptr) {}
			const FunctionSignature * signature;
			FunctionPartData partData;
		};

		// Log an error
		template<class... Args>
		void Error(const char * format, Args&&... args)
		{
			if (m_error)
				return;
			m_error = true;
			if (m_name.empty())
				LogWrite("Error at ");
			else
				LogWrite("Error in %s at ", m_name.c_str());
			if (m_currentSymbol == m_symbolList.end())
				LogWrite("end of script: ");
			else
				LogWrite("line %i, column %i: ", m_currentSymbol->lineNumber, m_currentSymbol->columnNumber);
			LogWriteLine(format, std::forward<Args>(args)...);
		}

		// Hash and register variable or property name and ID mapping
		RuntimeID VariableNameToRuntimeID(const String & name);

		// Assign a variable or check that it exists
		void VariableAssign(const String & name);
		bool VariableExists(const String & name) const;

		// Begin or end a new execution frame, like with a function
		void FrameBegin();
		void FrameEnd();

		// Begin or end current execution scope
		void ScopeBegin();
		void ScopeEnd();

		// Retrieve a precedence value for the specified operator
		uint32_t GetOperatorPrecedence(Opcode opcode) const;

		// Check to see if the symbol is a newline or at the end of the list
		bool IsSymbolValid(SymbolListCItr symbol) const;

		// Check a string to see if it's a library name
		bool IsLibraryName(const String & name) const;

		// Check to see if this is a property name
		bool IsPropertyName(const String & libraryName, const String & propertyName) const;

		// Emit functions write to internal bytecode buffer
		void EmitAddress(size_t address);
		size_t EmitAddressPlaceholder();
		void EmitAddressBackfill(size_t address);
		void EmitCount(uint32_t count);
		void EmitName(const String & name);
		void EmitOpcode(Opcode opcode);
		void EmitValue(const Variant & value);
		void EmitId(RuntimeID id);
		void EmitIndex(int32_t index);
		void EmitValueType(ValueType type);

		// Finalize bytecode header with final size
		void WriteBytecodeHeader();

		// Write optional debug info
		void WriteDebugInfo();

		// Advance to next sumbol
		void NextSymbol();

		// Returns false and flags an error if the current symbol does not match param.  NextSymbol() is
		// called and true is returned on success.
		bool Expect(SymbolType symbol);

		// If the current symbol matches the parameter, NextSymbol() is called and the function returns true.
		bool Accept(SymbolType symbol);

		// Check for existance of the specified symbol type or content at the current position.  
		// The state of the parser is guaranteed not to be altered.  Returns true or non-null on success.
		bool Check(SymbolType symbol) const;
		bool CheckBinaryOperator() const;
		bool CheckName() const;
		bool CheckValue() const;
		bool CheckValueType() const;
		bool CheckFunctionNamePart() const;
		bool CheckVariable(SymbolListCItr currSym, size_t * symCount = nullptr) const;
		bool CheckVariable() const;
		bool CheckProperty(SymbolListCItr currSym, size_t * symCount = nullptr) const;
		bool CheckProperty(size_t * symCount = nullptr) const;
		bool CheckPropertyName(LibraryIPtr library, SymbolListCItr currSym, size_t * symCount) const;
		String CheckLibraryName() const;
		bool CheckFunctionCallPart(const FunctionSignatureParts & parts, size_t partsIndex, SymbolListCItr currSym, SymbolListCItr endSym, FunctionMatch & match) const;
		FunctionMatch CheckFunctionCall(const FunctionSignature & signature, SymbolListCItr currSym, SymbolListCItr endSym, bool skipInitialParam) const;
		FunctionMatch CheckFunctionCall(const FunctionList & functionList, SymbolListCItr currSym, SymbolListCItr endSym, bool skipInitialParam) const;
		FunctionMatch CheckFunctionCall(LibraryIPtr library, SymbolListCItr currSym, SymbolListCItr endSym, bool skipInitialParam) const;
		FunctionMatch CheckFunctionCall(bool skipInitialParam, SymbolListCItr currSym, SymbolListCItr endSym) const;
		FunctionMatch CheckFunctionCall(bool skipInitialParam, SymbolListCItr endSym) const;
		FunctionMatch CheckFunctionCall() const;

		// Parsing functions advance the current symbol, looking for a pattern of symbols
		// and injecting the compiled results into the bytecode buffer.
		VisibilityType ParseScope();
		Opcode ParseBinaryOperator();
		Variant ParseValue();
		ValueType ParseValueType();
		String ParseName();
		String ParseMultiName(std::initializer_list<SymbolType> symbols);
		String ParseVariable();
		bool ParseSubscript();
		void ParsePropertyDeclaration(VisibilityType scope, bool readOnly);
		PropertyName ParsePropertyName();
		PropertyName ParsePropertyNameParts(LibraryIPtr library);
		String ParseFunctionNamePart();
		FunctionSignature ParseFunctionSignature(VisibilityType access);
		void ParseFunctionDefinition(VisibilityType scope);
		void ParseFunctionCall(const FunctionMatch & match);
		void ParseCast();
		void ParseSubexpressionOperand(bool required, SymbolListCItr endSymbol);
		void ParseSubexpression(SymbolListCItr endSymbol);
		void ParseSubexpression();
		void ParseExpression(SymbolListCItr endSymbol);
		void ParseExpression();
		void ParseErase();
		void ParseIncDec();
		void ParseIfElse();
		void ParseLoop();
		bool ParseStatement();
		void ParseBlock();
		void ParseLibraryImports();
		void ParseLibraryDeclaration();
		void ParseScript();

	private:
		using IDNameMap = std::map <RuntimeID, String, std::less<RuntimeID>, Allocator<std::pair<const RuntimeID, String>>>;

		// Runtime object
		RuntimeIPtr m_runtime;

		// Unique name
		String m_name;

		// Symbol list to parse
		const SymbolList & m_symbolList;

		// Current symbol being parsed
		SymbolListCItr m_currentSymbol;

		// Last parsed line
		uint32_t m_lastLine;

		// Signal an error
		bool m_error;

		// Break jump backfill address
		size_t m_breakAddress;

		// Bytecode data buffer
		BufferPtr m_bytecode;

		// Writes data to an output buffer
		BinaryWriter m_writer;

		// Write opcode debug data
		std::vector<DebugLineEntry, Allocator<DebugLineEntry>> m_debugLines;

		// Current library;
		LibraryIPtr m_library;

		// Local function definitions
		FunctionList m_localFunctions;

		// Library import list
		std::list<String, Allocator<String>> m_importList;

		// Keep track of variables currently in scope
		VariableStackFrame m_variableStackFrame;

		// ID to name mapping for debug output
		IDNameMap m_idNameMap;
	};

} // namespace Jinx::Impl

#endif // JX_PARSER_H__
