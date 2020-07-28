ifndef IMPERAS_HOME
  IMPERAS_ERROR := $(error "IMPERAS_HOME not defined, please setup Imperas/OVP environment")
endif
IMPERAS_HOME := $(shell getpath.exe "$(IMPERAS_HOME)")
include $(IMPERAS_HOME)/bin/Makefile.include

#
# Makefile to build the test applications and run platform simulation
#

all: applications modules 

modules:
	$(V) $(MAKE) -C module

applications:
	$(V) $(MAKE) -C application

# Start simulaiton
run: modules applications
	@echo $(RUN_ARGS)
	@echo "Running Imperas Simulation Platform"
	$(V) harness.exe --modulefile module/model.${IMPERAS_SHRSUF} \
	                 --program P0=application/app1.OR1K.elf \
	                 --program P1=application/app2.RISCV32I.elf \
                     --program P2=application/app3.RISCV32I.elf \
                     --output imperas.log

# Launch Imperas in interactive mode 
debug: modules applications
	$(V) harness.exe --modulefile module/model.${IMPERAS_SHRSUF} \
	                 --program P0=application/app1.OR1K.elf \
	                 --program P1=application/app2.RISCV32I.elf \
                     --program P2=application/app3.RISCV32I.elf \
	                 --output imperas.log \
                     --mpdconsole

gui: modules applications
	@echo "Launching Imperas Simulation Platform (iGui)"
	$(V) harness.exe --modulefile module/model.${IMPERAS_SHRSUF} \
	                 --program P0=application/app1.OR1K.elf \
	                 --program P1=application/app2.RISCV32I.elf \
                     --program P2=application/app3.RISCV32I.elf \
                     --output imperas.log\
                     --mpdigui

clean:
	- rm -f idebug.log
	- $(MAKE) -C application clean
	- $(MAKE) -C module clean

help:
	@echo The following targets are available to start simulation
	@echo debug   : run simulation using starting in MPD console mode
	@echo gui     : run simulation using starting eGui
