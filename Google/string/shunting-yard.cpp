/* Evaluate calculator expressions 
 * 1. Use below "Shunting yard algorithm" to convert expression to RPN
 * 2. Use stack to evaluate RPN
 * */

SHUNTING_YARD:

while there are tokens to be read:
	read a token.
	if the token is a number, then push it to the output queue. 
	if the token is an operator, then:
		while ((there is an operator at the top of the operator stack with
			greater precedence) or (the operator at the top of the operator stack has
                        equal precedence and the operator is left associative)) and
                      (the operator at the top of the stack is not a left bracket): // if left bracket on top of stack, push operator
				pop operators from the operator stack, onto the output queue. // in while
		push the read operator onto the operator stack. // out of while
	if the token is a left bracket (i.e. "("), then:
		push it onto the operator stack.
	if the token is a right bracket (i.e. ")"), then:
		while the operator at the top of the operator stack is not a left bracket:
			pop operators from the operator stack onto the output queue.
		pop the left bracket from the stack.
		/* if the stack runs out without finding a left bracket, then there are
		mismatched parentheses. */
if there are no more tokens to read:
	while there are still operator tokens on the stack:
		/* if the operator token on the top of the stack is a bracket, then
		there are mismatched parentheses. */
		pop the operator onto the output queue.
exit.
