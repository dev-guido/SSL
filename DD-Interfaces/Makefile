all: tests verTablas

verTablas: Conversion.o
	gcc TablasDeConversion.c Conversion.o -o verTablas

ConversionTest: Conversion.o
	gcc ConversionTest.c Conversion.o -lm -o ConversionTest

Conversion.o:
	gcc -c Conversion.c

tests: ConversionTest
	./ConversionTest

clean:
	rm -f verTablas ConversionTest *.o
