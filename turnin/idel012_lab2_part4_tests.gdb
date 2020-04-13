# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below
test "PINA: 0x00, PINB: 0x00, PINC: 0x00  => PORTD:0x00"
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x00
checkResult

test "PINA: 0x0A, PINB: 0x0A, PINC: 0x0A  => PORTD:0x1C"
setPINA 0x0A
setPINB 0x0A
setPINC 0x0A
continue 5
expectPORTD 0x1C
checkResult 

test "PINA: 0x2F, PINB: 0x2F, PINC: 0x2F  => PORTD:0x8D"
setPINA 0x2F
setPINB 0x2F
setPINC 0x2F
continue 5
expectPORTD 0x8D
checkResult

test "PINA: 0x64, PINB: 0x01, PINC: 0x01  => PORTD:0xCC"
setPINA 0x64
setPINB 0x01
setPINC 0x01
continue 5
expectPORTD 0x66
checkResult

test "PINA: 0x64, PINB: 0x64, PINC: 0x01  => PORTD:0xCB"
setPINA 0x64
setPINB 0x64
setPINC 0x01
continue 5
expectPORTD 0xCB
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
