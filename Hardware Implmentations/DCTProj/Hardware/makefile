NAME = DCT
LOCAL_CONFIG = -legup-config=../config.tcl
SRCS = ../tests.c 
GUI_BASE_DIR = ../
LEVEL = $(LEGUP_ROOT_DIR)/examples
ifneq ("$(wildcard $(GUI_BASE_DIR)Makefile.user)","")
include $(GUI_BASE_DIR)Makefile.user
endif
include $(LEVEL)/Makefile.common
