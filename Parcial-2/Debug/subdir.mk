################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../stringTest.cc 

CPP_SRCS += \
../DatClima.cpp \
../EstacionMeteo.cpp \
../Fecha.cpp \
../Hora.cpp \
../Menu.cpp 

CC_DEPS += \
./stringTest.d 

CPP_DEPS += \
./DatClima.d \
./EstacionMeteo.d \
./Fecha.d \
./Hora.d \
./Menu.d 

OBJS += \
./DatClima.o \
./EstacionMeteo.o \
./Fecha.o \
./Hora.o \
./Menu.o \
./stringTest.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cc subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./DatClima.d ./DatClima.o ./EstacionMeteo.d ./EstacionMeteo.o ./Fecha.d ./Fecha.o ./Hora.d ./Hora.o ./Menu.d ./Menu.o ./stringTest.d ./stringTest.o

.PHONY: clean--2e-

