/* lldb and gdb both use the DebugSymbols framework to find dSYM files.

// /Users/jrmuizel/src/lldb/source/Host/macosx/Symbols.cpp

// DBGCopyFullDSYMURLForUUID

// DBGCopyDSYMURLForUUID

// https://github.com/eightcien/lldb/blob/211925ad15468061135882005efd9d17e9ce8193/source/Plugins/SymbolVendor/MacOSX/SymbolVendorMacOSX.cpp

/* atos uses CoreSymbolication which uses DebugSymbols
                U _DBGCopyDSYMPropertyLists
                U _DBGCopyFullDSYMURLForUUID
                U _DBGCopyFullDSYMURLForUUIDWithOptions

*/

/* get the UUID from a binary with llvm-objdump -macho -private-headers [binary]
      cmd LC_UUID
      cmdsize 24
      uuid 20D9F286-538F-3A12-98E0-91379CB90844
*/
