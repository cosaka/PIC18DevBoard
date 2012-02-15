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
CND_CONF=PIC18DevBoard_SDCC
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/83377035/lcd_driver.o ${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o ${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o ${OBJECTDIR}/source/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/83377035/lcd_driver.o.d ${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o.d ${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o.d ${OBJECTDIR}/source/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/83377035/lcd_driver.o ${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o ${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o ${OBJECTDIR}/source/main.o


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
	${MAKE}  -f nbproject/Makefile-PIC18DevBoard_SDCC.mk dist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/83377035/lcd_driver.o: ../../Drivers/lcd_driver.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/83377035 
	${RM} ${OBJECTDIR}/_ext/83377035/lcd_driver.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 ../../Drivers/lcd_driver.c  -o${OBJECTDIR}/_ext/83377035/lcd_driver.o
	
${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o: ../../Drivers/pmp_sw_driver.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/83377035 
	${RM} ${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 ../../Drivers/pmp_sw_driver.c  -o${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o
	
${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o: ../../HardwareProfiles/hardware_PIC18DevBoard.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1466353586 
	${RM} ${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 ../../HardwareProfiles/hardware_PIC18DevBoard.c  -o${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o
	
${OBJECTDIR}/source/main.o: source/main.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/source 
	${RM} ${OBJECTDIR}/source/main.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 source/main.c  -o${OBJECTDIR}/source/main.o
	
else
${OBJECTDIR}/_ext/83377035/lcd_driver.o: ../../Drivers/lcd_driver.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/83377035 
	${RM} ${OBJECTDIR}/_ext/83377035/lcd_driver.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 ../../Drivers/lcd_driver.c  -o${OBJECTDIR}/_ext/83377035/lcd_driver.o
	
${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o: ../../Drivers/pmp_sw_driver.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/83377035 
	${RM} ${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 ../../Drivers/pmp_sw_driver.c  -o${OBJECTDIR}/_ext/83377035/pmp_sw_driver.o
	
${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o: ../../HardwareProfiles/hardware_PIC18DevBoard.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/_ext/1466353586 
	${RM} ${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 ../../HardwareProfiles/hardware_PIC18DevBoard.c  -o${OBJECTDIR}/_ext/1466353586/hardware_PIC18DevBoard.o
	
${OBJECTDIR}/source/main.o: source/main.c  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} ${OBJECTDIR}/source 
	${RM} ${OBJECTDIR}/source/main.o 
	${MP_CC} --debug-ralloc --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -c -mpic16 -p18f4520 source/main.c  -o${OBJECTDIR}/source/main.o
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  --debug-ralloc -Wl-c -Wl-m --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -mpic16 -p18f4520 ${OBJECTFILES}  -odist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} 
else
dist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC}  --debug-ralloc -Wl-c -Wl-m --use-non-free --pstack-model=small -D__18F4520 -D_HARDWARE_PIC18DEVBOARD -I".\source" -I"..\..\Drivers" -I"..\..\HardwareProfiles" -mpic16 -p18f4520 ${OBJECTFILES}  -odist/${CND_CONF}/${IMAGE_TYPE}/HelloLCD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/PIC18DevBoard_SDCC
	${RM} -r dist/PIC18DevBoard_SDCC

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
