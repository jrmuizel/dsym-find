CFLAGS=-g
LDFLAGS=-F/System/Library/Frameworks -F/System/Library/PrivateFrameworks -framework CoreFoundation -framework DebugSymbols
dsym-find: dsym-find.o

clean:
	rm dsym-find dsym-find.o
