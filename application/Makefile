IMPERAS_HOME := $(shell getpath.exe "$(IMPERAS_HOME)")
include $(IMPERAS_HOME)/bin/Makefile.include

ifndef IMPERAS_HOME
  IMPERAS_ERROR := $(error "IMPERAS_HOME not defined")
endif


CROSS0?=OR1K
CROSS1?=RISCV32I
CROSS2?=RISCV32I

all: app1.$(CROSS0).elf app2.$(CROSS1).elf app3.$(CROSS2).elf

-include $(IMPERAS_HOME)/lib/$(IMPERAS_ARCH)/CrossCompiler/$(CROSS0).makefile.include
-include $(IMPERAS_HOME)/lib/$(IMPERAS_ARCH)/CrossCompiler/$(CROSS1).makefile.include
-include $(IMPERAS_HOME)/lib/$(IMPERAS_ARCH)/CrossCompiler/$(CROSS2).makefile.include


ifeq ($($(CROSS0)_CC),)
    IMPERAS_ERROR := $(error "Please install the $(CROSS0)_CC toolchain")
endif

ifeq ($($(CROSS1)_CC),)
    IMPERAS_ERROR := $(error "Please install the $(CROSS1)_CC toolchain")
endif

ifeq ($($(CROSS2)_CC),)
    IMPERAS_ERROR := $(error "Please install the $(CROSS2)_CC toolchain")
endif


app1.$(CROSS0).elf: app1.$(CROSS0).o
	$(V) echo "Linking Application $@"
	$(V) $($(CROSS0)_LINK) -g -o $@  $^  $($(CROSS0)_LDFLAGS)

app1.$(CROSS0).o: app1.c
	$(V) echo "Compiling Application $@"
	$(V) $($(CROSS0)_CC) -g -c  $($(CROSS0)_CFLAGS) -D$(CROSS0)  -o $@  $<

app2.$(CROSS1).elf: app2.$(CROSS1).o
	$(V) echo "Linking Application $@"
	$(V) $($(CROSS1)_LINK) -g -o $@  $^  $($(CROSS1)_LDFLAGS)

app2.$(CROSS1).o: app2.c
	$(V) echo "Compiling Application $@"
	$(V) $($(CROSS1)_CC) -g -c  $($(CROSS1)_CFLAGS) -D$(CROSS1)  -o $@  $<

app3.$(CROSS2).elf: app3.$(CROSS2).o
	$(V) echo "Linking Application $@"
	$(V) $($(CROSS2)_LINK) -g -o $@  $^  $($(CROSS2)_LDFLAGS)

app3.$(CROSS2).o: app3.c
	$(V) echo "Compiling Application $@"
	$(V) $($(CROSS2)_CC) -g -c  $($(CROSS2)_CFLAGS) -D$(CROSS2)  -o $@  $<

clean:
	- rm -f app1.$(CROSS0).elf app1.$(CROSS0).o app2.$(CROSS1).elf app2.$(CROSS1).o app3.$(CROSS2).elf app3.$(CROSS2).o
