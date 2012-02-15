#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
SHELL=cmd.exe
# Adding MPLAB X bin directory to path
PATH:=C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/:$(PATH)
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=SDCC
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/source/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/source/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/source/main.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH="C:\Program Files (x86)\Java\jre6/bin/"
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC="C:\Program Files\SDCC\bin\sdcc.exe"
# MP_BC is not defined
# MP_AS is not defined
# MP_LD is not defined
# MP_AR is not defined
DEP_GEN=${MP_JAVA_PATH}java -jar "C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/extractobjectdependencies.jar" 
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps
MP_CC_DIR="C:\Program Files\SDCC\bin"
# MP_BC_DIR is not defined
# MP_AS_DIR is not defined
# MP_LD_DIR is not defined
# MP_AR_DIR is not defined
# MP_BC_DIR is not defined

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-SDCC.mk dist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/source/main.o: source/main.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/source 
	${RM} ${OBJECTDIR}/source/main.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -c -mpic16 -p18f4520 source/main.c  -o${OBJECTDIR}/source/main.o
	
else
${OBJECTDIR}/source/main.o: source/main.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/source 
	${RM} ${OBJECTDIR}/source/main.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -c -mpic16 -p18f4520 source/main.c  -o${OBJECTDIR}/source/main.o
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  --debug-ralloc -Wl-c -Wl-m --use-non-free --pstack-model=small -mpic16 -p18f4520 ${OBJECTFILES}  -odist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} 
else
dist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  --debug-ralloc -Wl-c -Wl-m --use-non-free --pstack-model=small -mpic16 -p18f4520 ${OBJECTFILES}  -odist/${CND_CONF}/${IMAGE_TYPE}/BasicDemo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/SDCC
	${RM} -r dist/SDCC

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
