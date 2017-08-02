ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPRO")
endif

#---------------------------------------------------------------------------------
# BUILD_FLAGS: List of extra build flags to add.
# NO_BUILDTOOLS: Do not include buildtools.
# ENABLE_EXCEPTIONS: Enable C++ exceptions.
#---------------------------------------------------------------------------------

include buildtools/make_base
