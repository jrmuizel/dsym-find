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
#include <CoreFoundation/CoreFoundation.h>

        CFURLRef DBGCopyFullDSYMURLForUUID(CFUUIDRef uuid, CFURLRef exec_url);
        CFDictionaryRef DBGCopyDSYMPropertyLists(CFURLRef dsym_url);

int main(int argc, char **argv) {
        if (argc < 2) {
                printf("usage: dsym-find executable uuid\n");
                printf("get the UUID from a binary with llvm-objdump -macho -private-headers [binary]\n");
                exit(1);
        }
        char *path = argv[1];
        CFURLRef url = CFURLCreateFromFileSystemRepresentation(
                                                NULL, (const UInt8 *)path, strlen(path),
                                                FALSE
                                               );
        CFUUIDRef uuid = CFUUIDCreateFromString(kCFAllocatorDefault, CFStringCreateWithCString(kCFAllocatorDefault, argv[2], kCFStringEncodingMacRoman));

        CFURLRef dsym_url = DBGCopyFullDSYMURLForUUID(uuid, url);
        if (dsym_url) {
                char dsym_path[PATH_MAX];
                CFURLGetFileSystemRepresentation(dsym_url, true, dsym_path, sizeof(dsym_path) - 1);
                printf("path: %s\n", dsym_path);
        } else {
                printf("dsym not found\n");
        }
}
