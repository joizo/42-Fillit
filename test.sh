clear
make

echo "List of NOT valid files:"
(./fillit inp/empty)
(./fillit inp/invalid_input0)
(./fillit inp/invalid_input1)
(./fillit inp/invalid_input2)
(./fillit inp/invalid_input3)
(./fillit inp/invalid_input4)
(./fillit inp/invalid_input5)
(./fillit inp/invalid_input6)
(./fillit inp/invalid_input7)
(./fillit inp/invalid_input8)
(./fillit inp/invalid_input9)
(./fillit inp/invalid_input10)
(./fillit inp/invalid_input11)
(./fillit inp/invalid_input12)

echo ""
echo "List of VALID files:"

time (./fillit inp/valid_input)
time (./fillit inp/valid_input0)
time (./fillit inp/valid_input1)
time (./fillit inp/valid_input2)
time (./fillit inp/valid_input3)
time (./fillit inp/valid_input4)

echo "Testing 26 tetr. file:"
time (./fillit inp/valid_input5)
echo "Testing 27 tetr. file:"
time (./fillit inp/valid_input6)


