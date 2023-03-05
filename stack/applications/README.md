# Applications of Stack

## Shunting Yard Algorithm

The shunting-yard algorithm is a method for parsing infix expressions and converting them to postfix notation, which is also known as reverse Polish notation (RPN). The algorithm was developed by Edsger Dijkstra in 1961 and is widely used in programming languages compilers and calculators.

The algorithm uses a stack to store operators and a queue to output the postfix expression. It scans the infix expression from left to right and performs the following steps for each token:

1. If the token is an operand (number), it is added to the output queue.
2. If the token is an operator, it is added to the operator stack. Before adding it, all operators with higher or equal precedence that are on top of the stack are popped and added to the output queue.
3. If the token is a left parenthesis, it is added to the operator stack.
4. If the token is a right parenthesis, all operators on top of the stack are popped and added to the output queue until a left parenthesis is found. The left parenthesis is popped but not added to the output queue.
5. After scanning the entire infix expression, any remaining operators on the stack are popped and added to the output queue.

The output queue now contains the postfix expression, which can be evaluated using a stack-based algorithm. The postfix notation is useful because it eliminates the need for parentheses and allows for simpler evaluation of expressions.

Overall, the shunting-yard algorithm is a useful and efficient method for converting infix expressions to postfix notation.
