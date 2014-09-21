#
#  Copyright (c) 2011 Arduino.  All right reserved.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#

# Makefile for compiling libsys_xxx

SUBMAKE_OPTIONS=--no-builtin-rules --no-builtin-variables --no-print-directory

#-------------------------------------------------------------------------------
# Rules
#-------------------------------------------------------------------------------

#
all: libsys_lpc1114

.PHONY: libsys_lpc1114
libsys_lpc1114:
	@echo ------------------------------------------------------------------------------------
	@echo --- Making $@
	@echo ---
	@$(MAKE) CHIP=__LPC1114__ $(SUBMAKE_OPTIONS) -f system.mk
	@echo ------------------------------------------------------------------------------------


.PHONY: clean
clean:
	@echo ------------------------------------------------------------------------------------
	@echo --- Cleaning lpc1114 release and debug
	@$(MAKE) CHIP=__LPC1114__ $(SUBMAKE_OPTIONS) -f system.mk $@
	@$(MAKE) CHIP=__LPC1114__ DEBUG=1 $(SUBMAKE_OPTIONS) -f system.mk $@
	@echo ------------------------------------------------------------------------------------


