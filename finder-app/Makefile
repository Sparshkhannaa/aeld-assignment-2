CC:= $(CROSS_COMPILE)gcc
Target = writer
SRCS = writer.c
default: $(Target)

$(Target): $(SRCS)
	$(CC) -o $@ $(SRCS)

clean:
	rm -f $(Target)