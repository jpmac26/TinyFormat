TARGET := 3DS
LIBRARY := 0

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path/to/devkitPro>")
endif


NAME := TinyFormat

BUILD_DIR := build
OUTPUT_DIR := output
INCLUDE_DIRS := include
SOURCE_DIRS := source

LIBRARY_DIRS :=
LIBRARIES :=

BUILD_FLAGS := -Wall
BUILD_FLAGS_CC :=
BUILD_FLAGS_CXX :=
RUN_FLAGS :=

VERSION_PARTS := $(subst ., ,$(shell git describe --tags --abbrev=0))

VERSION_MAJOR := $(word 1, $(VERSION_PARTS))
VERSION_MINOR := $(word 2, $(VERSION_PARTS))
VERSION_MICRO := $(word 3, $(VERSION_PARTS))

TITLE := $(NAME)
DESCRIPTION := A small utility to format Sys/EmuNAND.
AUTHOR := javiMaD/CaptainSwag101

LIBRARY_DIRS += $(DEVKITPRO)/libctru
LIBRARIES += ctru

PRODUCT_CODE := CTR-P-TNYF
UNIQUE_ID := 0xD8317

CATEGORY := Application
USE_ON_SD := true

MEMORY_TYPE := Application
SYSTEM_MODE := 64MB
SYSTEM_MODE_EXT := Legacy
CPU_SPEED := 268MHz
ENABLE_L2_CACHE := true

ICON_FLAGS := --flags visible,ratingrequired,recordusage --cero 153 --esrb 153 --usk 153 --pegigen 153 --pegiptr 153 --pegibbfc 153 --cob 153 --grb 153 --cgsrr 153

#ROMFS_DIR := romfs
BANNER_AUDIO := resources/audio.wav
BANNER_IMAGE := resources/banner.png
ICON := resources/icon.png
#LOGO := resources/logo.bcma.lz


include buildtools/make_base
