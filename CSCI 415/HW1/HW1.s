# Sean Tesch    10/10/17
# CS 415        Homework 3
.init _main
.segment 32768

_main:
    lda r10, $1
    lda r11, $40
    lda r12, $1

    lda r13, $3920
    lda r14, $7088
    lda r15, $3860
    lda r16, $745
    lda r17, $50
    lda r18, $4

top_func:
    beq r10, r11, end

    mul r19, r10, r10
    mul r19, r19, r10
    mul r19, r19, r10
    mul r19, r19, r10 # x^5

    mul r20, r10, r10
    mul r20, r20, r10
    mul r20, r20, r10
    mul r20, r17, r20  # 50x^4

    mul r21, r10, r10
    mul r21, r21, r10
    mul r21, r21, r16 # 745x^3

    mul r22, r10, r10
    mul r22, r22, r15 # 3860x^2

    mul r23, r14, r10 # 7088x

    sub r24, r19, r20
    add r25, r24, r21
    sub r26, r25, r22
    add r27, r26, r23
    sub r28, r27, r13

    mov r59, r28

    call _printint

    add r10, r10, r12

    jmp top_func

end:
    exit

string: .string "\n"
