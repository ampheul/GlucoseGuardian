# Artificial Pancreas

This is a software application which emulates the function of a human pancreas.
The Artificial Pancreas takes in insulin readings from an external device and sends an insulin dosage
as a result. It can also store patient information to enhance insulin dosage and respond to emergency situations.

-------------Stage 3 HOW TO RUN TESTS-------------------------

For the completed tickets, here are the tests to run:

	Error message will be displayed if tests fail
	Nothing will be displayed if tests pass 
	(In some cases, "Invalid glucose reading" prints as it should) 

g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestAge.cpp
g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestGluc.cpp
g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestExercise.cpp
g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestMeal.cpp

Please run this one at 10pm at night as it takes into consideration the current time and compares it to a user defined bed time:
g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestSleep.cpp