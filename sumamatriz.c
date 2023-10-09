´´´
Este es el codigo en C, el cual realiza una suma de dos matrices que es determinada de manera aleatoria
´´´

´´´
#include <stdio.h>   // Including the standard input-output header file for functions like printf.
#include <stdlib.h>  // Including the standard library header file for functions like malloc and srand.
#include <time.h>    // Including the time header file for generating random numbers.
 
/**
 * Generates a random matrix of size rows x columns.
 *
 * @param rows: The number of rows in the matrix.
 * @param columns: The number of columns in the matrix.
 * @return: A dynamically allocated 2D array representing the random matrix.
 */
int** generateRandomMatrix(int rows, int columns) {
    // Allocating memory for the matrix.
    int** matrix = (int**) malloc(rows * sizeof(int*));
    if (matrix == NULL) {  // Checking for unsuccessful memory allocation.
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);  // Exiting the program with a failure status.
    }
 
    // Generating random numbers for each element in the matrix.
    srand(time(NULL));  // Seeding the random number generator with the current time.
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(columns * sizeof(int));
        if (matrix[i] == NULL) {  // Checking for unsuccessful memory allocation.
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);  // Exiting the program with a failure status.
        }
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 100;  // Generating a random number between 0 and 99.
        }
    }
 
    return matrix;  // Returning the generated matrix.
}
 
/**
 * Sums two matrices element-wise and stores the result in a new matrix.
 *
 * @param matrix1: The first matrix.
 * @param matrix2: The second matrix.
 * @param rows: The number of rows in the matrices.
 * @param columns: The number of columns in the matrices.
 * @return: A dynamically allocated 2D array representing the sum of the matrices.
 */
int** sumMatrices(int** matrix1, int** matrix2, int rows, int columns) {
    // Allocating memory for the result matrix.
    int** result = (int**) malloc(rows * sizeof(int*));
    if (result == NULL) {  // Checking for unsuccessful memory allocation.
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);  // Exiting the program with a failure status.
    }
 
    // Summing the elements of the matrices element-wise.
    for (int i = 0; i < rows; i++) {
        result[i] = (int*) malloc(columns * sizeof(int));
        if (result[i] == NULL) {  // Checking for unsuccessful memory allocation.
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);  // Exiting the program with a failure status.
        }
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
 
    return result;  // Returning the sum matrix.
}
 
// Usage example for generateRandomMatrix and sumMatrices
 
int main() {
    int rows = 3;
    int columns = 3;
 
    // Generate two random matrices.
    int** matrix1 = generateRandomMatrix(rows, columns);
    int** matrix2 = generateRandomMatrix(rows, columns);
 
    // Print the generated matrices.
    printf("Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 
    printf("Matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 
    // Sum the matrices.
    int** sum = sumMatrices(matrix1, matrix2, rows, columns);
 
    // Print the sum matrix.
    printf("Sum Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 
    // Free allocated memory to avoid memory leaks.
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(sum[i]);
    }
    free(matrix1);
    free(matrix2);
    free(sum);
 
    return 0;
}
´´´
´´´
Este es el codigo de ensamblador
´´´
sumamatriz:     file format elf32-littlearm


Disassembly of section .init:

000103e4 <_init>:
   103e4:	e92d4008 	push	{r3, lr}
   103e8:	eb000038 	bl	104d0 <call_weak_fn>
   103ec:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000103f0 <.plt>:
   103f0:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
   103f4:	e59fe004 	ldr	lr, [pc, #4]	; 10400 <.plt+0x10>
   103f8:	e08fe00e 	add	lr, pc, lr
   103fc:	e5bef008 	ldr	pc, [lr, #8]!
   10400:	00010c00 	.word	0x00010c00

00010404 <printf@plt>:
   10404:	e28fc600 	add	ip, pc, #0, 12
   10408:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   1040c:	e5bcfc00 	ldr	pc, [ip, #3072]!	; 0xc00

00010410 <free@plt>:
   10410:	e28fc600 	add	ip, pc, #0, 12
   10414:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10418:	e5bcfbf8 	ldr	pc, [ip, #3064]!	; 0xbf8

0001041c <time@plt>:
   1041c:	e28fc600 	add	ip, pc, #0, 12
   10420:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10424:	e5bcfbf0 	ldr	pc, [ip, #3056]!	; 0xbf0

00010428 <puts@plt>:
   10428:	e28fc600 	add	ip, pc, #0, 12
   1042c:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10430:	e5bcfbe8 	ldr	pc, [ip, #3048]!	; 0xbe8

00010434 <malloc@plt>:
   10434:	e28fc600 	add	ip, pc, #0, 12
   10438:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   1043c:	e5bcfbe0 	ldr	pc, [ip, #3040]!	; 0xbe0

00010440 <__libc_start_main@plt>:
   10440:	e28fc600 	add	ip, pc, #0, 12
   10444:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10448:	e5bcfbd8 	ldr	pc, [ip, #3032]!	; 0xbd8

0001044c <__gmon_start__@plt>:
   1044c:	e28fc600 	add	ip, pc, #0, 12
   10450:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10454:	e5bcfbd0 	ldr	pc, [ip, #3024]!	; 0xbd0

00010458 <exit@plt>:
   10458:	e28fc600 	add	ip, pc, #0, 12
   1045c:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10460:	e5bcfbc8 	ldr	pc, [ip, #3016]!	; 0xbc8

00010464 <srand@plt>:
   10464:	e28fc600 	add	ip, pc, #0, 12
   10468:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   1046c:	e5bcfbc0 	ldr	pc, [ip, #3008]!	; 0xbc0

00010470 <putchar@plt>:
   10470:	e28fc600 	add	ip, pc, #0, 12
   10474:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10478:	e5bcfbb8 	ldr	pc, [ip, #3000]!	; 0xbb8

0001047c <rand@plt>:
   1047c:	e28fc600 	add	ip, pc, #0, 12
   10480:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10484:	e5bcfbb0 	ldr	pc, [ip, #2992]!	; 0xbb0

00010488 <abort@plt>:
   10488:	e28fc600 	add	ip, pc, #0, 12
   1048c:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10490:	e5bcfba8 	ldr	pc, [ip, #2984]!	; 0xba8

Disassembly of section .text:

00010494 <_start>:
   10494:	e3a0b000 	mov	fp, #0
   10498:	e3a0e000 	mov	lr, #0
   1049c:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
   104a0:	e1a0200d 	mov	r2, sp
   104a4:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
   104a8:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
   104ac:	e59fc010 	ldr	ip, [pc, #16]	; 104c4 <_start+0x30>
   104b0:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
   104b4:	e59f000c 	ldr	r0, [pc, #12]	; 104c8 <_start+0x34>
   104b8:	e59f300c 	ldr	r3, [pc, #12]	; 104cc <_start+0x38>
   104bc:	ebffffdf 	bl	10440 <__libc_start_main@plt>
   104c0:	ebfffff0 	bl	10488 <abort@plt>
   104c4:	00010ba0 	.word	0x00010ba0
   104c8:	00010870 	.word	0x00010870
   104cc:	00010b40 	.word	0x00010b40

000104d0 <call_weak_fn>:
   104d0:	e59f3014 	ldr	r3, [pc, #20]	; 104ec <call_weak_fn+0x1c>
   104d4:	e59f2014 	ldr	r2, [pc, #20]	; 104f0 <call_weak_fn+0x20>
   104d8:	e08f3003 	add	r3, pc, r3
   104dc:	e7932002 	ldr	r2, [r3, r2]
   104e0:	e3520000 	cmp	r2, #0
   104e4:	012fff1e 	bxeq	lr
   104e8:	eaffffd7 	b	1044c <__gmon_start__@plt>
   104ec:	00010b20 	.word	0x00010b20
   104f0:	0000003c 	.word	0x0000003c

000104f4 <deregister_tm_clones>:
   104f4:	e59f0018 	ldr	r0, [pc, #24]	; 10514 <deregister_tm_clones+0x20>
   104f8:	e59f3018 	ldr	r3, [pc, #24]	; 10518 <deregister_tm_clones+0x24>
   104fc:	e1530000 	cmp	r3, r0
   10500:	012fff1e 	bxeq	lr
   10504:	e59f3010 	ldr	r3, [pc, #16]	; 1051c <deregister_tm_clones+0x28>
   10508:	e3530000 	cmp	r3, #0
   1050c:	012fff1e 	bxeq	lr
   10510:	e12fff13 	bx	r3
   10514:	00021048 	.word	0x00021048
   10518:	00021048 	.word	0x00021048
   1051c:	00000000 	.word	0x00000000

00010520 <register_tm_clones>:
   10520:	e59f0024 	ldr	r0, [pc, #36]	; 1054c <register_tm_clones+0x2c>
   10524:	e59f1024 	ldr	r1, [pc, #36]	; 10550 <register_tm_clones+0x30>
   10528:	e0411000 	sub	r1, r1, r0
   1052c:	e1a01141 	asr	r1, r1, #2
   10530:	e0811fa1 	add	r1, r1, r1, lsr #31
   10534:	e1b010c1 	asrs	r1, r1, #1
   10538:	012fff1e 	bxeq	lr
   1053c:	e59f3010 	ldr	r3, [pc, #16]	; 10554 <register_tm_clones+0x34>
   10540:	e3530000 	cmp	r3, #0
   10544:	012fff1e 	bxeq	lr
   10548:	e12fff13 	bx	r3
   1054c:	00021048 	.word	0x00021048
   10550:	00021048 	.word	0x00021048
   10554:	00000000 	.word	0x00000000

00010558 <__do_global_dtors_aux>:
   10558:	e92d4010 	push	{r4, lr}
   1055c:	e59f4018 	ldr	r4, [pc, #24]	; 1057c <__do_global_dtors_aux+0x24>
   10560:	e5d43000 	ldrb	r3, [r4]
   10564:	e3530000 	cmp	r3, #0
   10568:	18bd8010 	popne	{r4, pc}
   1056c:	ebffffe0 	bl	104f4 <deregister_tm_clones>
   10570:	e3a03001 	mov	r3, #1
   10574:	e5c43000 	strb	r3, [r4]
   10578:	e8bd8010 	pop	{r4, pc}
   1057c:	00021048 	.word	0x00021048

00010580 <frame_dummy>:
   10580:	eaffffe6 	b	10520 <register_tm_clones>

00010584 <generateRandomMatrix>:
   10584:	e92d4810 	push	{r4, fp, lr}
   10588:	e28db008 	add	fp, sp, #8
   1058c:	e24dd01c 	sub	sp, sp, #28
   10590:	e50b0020 	str	r0, [fp, #-32]	; 0xffffffe0
   10594:	e50b1024 	str	r1, [fp, #-36]	; 0xffffffdc
   10598:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
   1059c:	e1a03103 	lsl	r3, r3, #2
   105a0:	e1a00003 	mov	r0, r3
   105a4:	ebffffa2 	bl	10434 <malloc@plt>
   105a8:	e1a03000 	mov	r3, r0
   105ac:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
   105b0:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
   105b4:	e3530000 	cmp	r3, #0
   105b8:	1a000003 	bne	105cc <generateRandomMatrix+0x48>
   105bc:	e59f012c 	ldr	r0, [pc, #300]	; 106f0 <generateRandomMatrix+0x16c>
   105c0:	ebffff98 	bl	10428 <puts@plt>
   105c4:	e3a00001 	mov	r0, #1
   105c8:	ebffffa2 	bl	10458 <exit@plt>
   105cc:	e3a00000 	mov	r0, #0
   105d0:	ebffff91 	bl	1041c <time@plt>
   105d4:	e1a03000 	mov	r3, r0
   105d8:	e1a00003 	mov	r0, r3
   105dc:	ebffffa0 	bl	10464 <srand@plt>
   105e0:	e3a03000 	mov	r3, #0
   105e4:	e50b3010 	str	r3, [fp, #-16]
   105e8:	ea000038 	b	106d0 <generateRandomMatrix+0x14c>
   105ec:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
   105f0:	e1a01103 	lsl	r1, r3, #2
   105f4:	e51b3010 	ldr	r3, [fp, #-16]
   105f8:	e1a03103 	lsl	r3, r3, #2
   105fc:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
   10600:	e0824003 	add	r4, r2, r3
   10604:	e1a00001 	mov	r0, r1
   10608:	ebffff89 	bl	10434 <malloc@plt>
   1060c:	e1a03000 	mov	r3, r0
   10610:	e5843000 	str	r3, [r4]
   10614:	e51b3010 	ldr	r3, [fp, #-16]
   10618:	e1a03103 	lsl	r3, r3, #2
   1061c:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
   10620:	e0823003 	add	r3, r2, r3
   10624:	e5933000 	ldr	r3, [r3]
   10628:	e3530000 	cmp	r3, #0
   1062c:	1a000003 	bne	10640 <generateRandomMatrix+0xbc>
   10630:	e59f00b8 	ldr	r0, [pc, #184]	; 106f0 <generateRandomMatrix+0x16c>
   10634:	ebffff7b 	bl	10428 <puts@plt>
   10638:	e3a00001 	mov	r0, #1
   1063c:	ebffff85 	bl	10458 <exit@plt>
   10640:	e3a03000 	mov	r3, #0
   10644:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
   10648:	ea000019 	b	106b4 <generateRandomMatrix+0x130>
   1064c:	ebffff8a 	bl	1047c <rand@plt>
   10650:	e1a01000 	mov	r1, r0
   10654:	e51b3010 	ldr	r3, [fp, #-16]
   10658:	e1a03103 	lsl	r3, r3, #2
   1065c:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
   10660:	e0823003 	add	r3, r2, r3
   10664:	e5932000 	ldr	r2, [r3]
   10668:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   1066c:	e1a03103 	lsl	r3, r3, #2
   10670:	e0820003 	add	r0, r2, r3
   10674:	e59f3078 	ldr	r3, [pc, #120]	; 106f4 <generateRandomMatrix+0x170>
   10678:	e0c32193 	smull	r2, r3, r3, r1
   1067c:	e1a022c3 	asr	r2, r3, #5
   10680:	e1a03fc1 	asr	r3, r1, #31
   10684:	e0422003 	sub	r2, r2, r3
   10688:	e1a03002 	mov	r3, r2
   1068c:	e1a03103 	lsl	r3, r3, #2
   10690:	e0833002 	add	r3, r3, r2
   10694:	e1a02103 	lsl	r2, r3, #2
   10698:	e0833002 	add	r3, r3, r2
   1069c:	e1a03103 	lsl	r3, r3, #2
   106a0:	e0412003 	sub	r2, r1, r3
   106a4:	e5802000 	str	r2, [r0]
   106a8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   106ac:	e2833001 	add	r3, r3, #1
   106b0:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
   106b4:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
   106b8:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
   106bc:	e1520003 	cmp	r2, r3
   106c0:	baffffe1 	blt	1064c <generateRandomMatrix+0xc8>
   106c4:	e51b3010 	ldr	r3, [fp, #-16]
   106c8:	e2833001 	add	r3, r3, #1
   106cc:	e50b3010 	str	r3, [fp, #-16]
   106d0:	e51b2010 	ldr	r2, [fp, #-16]
   106d4:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
   106d8:	e1520003 	cmp	r2, r3
   106dc:	baffffc2 	blt	105ec <generateRandomMatrix+0x68>
   106e0:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
   106e4:	e1a00003 	mov	r0, r3
   106e8:	e24bd008 	sub	sp, fp, #8
   106ec:	e8bd8810 	pop	{r4, fp, pc}
   106f0:	00010bb0 	.word	0x00010bb0
   106f4:	51eb851f 	.word	0x51eb851f

000106f8 <sumMatrices>:
   106f8:	e92d4810 	push	{r4, fp, lr}
   106fc:	e28db008 	add	fp, sp, #8
   10700:	e24dd024 	sub	sp, sp, #36	; 0x24
   10704:	e50b0020 	str	r0, [fp, #-32]	; 0xffffffe0
   10708:	e50b1024 	str	r1, [fp, #-36]	; 0xffffffdc
   1070c:	e50b2028 	str	r2, [fp, #-40]	; 0xffffffd8
   10710:	e50b302c 	str	r3, [fp, #-44]	; 0xffffffd4
   10714:	e51b3028 	ldr	r3, [fp, #-40]	; 0xffffffd8
   10718:	e1a03103 	lsl	r3, r3, #2
   1071c:	e1a00003 	mov	r0, r3
   10720:	ebffff43 	bl	10434 <malloc@plt>
   10724:	e1a03000 	mov	r3, r0
   10728:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
   1072c:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
   10730:	e3530000 	cmp	r3, #0
   10734:	1a000003 	bne	10748 <sumMatrices+0x50>
   10738:	e59f012c 	ldr	r0, [pc, #300]	; 1086c <sumMatrices+0x174>
   1073c:	ebffff39 	bl	10428 <puts@plt>
   10740:	e3a00001 	mov	r0, #1
   10744:	ebffff43 	bl	10458 <exit@plt>
   10748:	e3a03000 	mov	r3, #0
   1074c:	e50b3010 	str	r3, [fp, #-16]
   10750:	ea00003d 	b	1084c <sumMatrices+0x154>
   10754:	e51b302c 	ldr	r3, [fp, #-44]	; 0xffffffd4
   10758:	e1a01103 	lsl	r1, r3, #2
   1075c:	e51b3010 	ldr	r3, [fp, #-16]
   10760:	e1a03103 	lsl	r3, r3, #2
   10764:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
   10768:	e0824003 	add	r4, r2, r3
   1076c:	e1a00001 	mov	r0, r1
   10770:	ebffff2f 	bl	10434 <malloc@plt>
   10774:	e1a03000 	mov	r3, r0
   10778:	e5843000 	str	r3, [r4]
   1077c:	e51b3010 	ldr	r3, [fp, #-16]
   10780:	e1a03103 	lsl	r3, r3, #2
   10784:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
   10788:	e0823003 	add	r3, r2, r3
   1078c:	e5933000 	ldr	r3, [r3]
   10790:	e3530000 	cmp	r3, #0
   10794:	1a000003 	bne	107a8 <sumMatrices+0xb0>
   10798:	e59f00cc 	ldr	r0, [pc, #204]	; 1086c <sumMatrices+0x174>
   1079c:	ebffff21 	bl	10428 <puts@plt>
   107a0:	e3a00001 	mov	r0, #1
   107a4:	ebffff2b 	bl	10458 <exit@plt>
   107a8:	e3a03000 	mov	r3, #0
   107ac:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
   107b0:	ea00001e 	b	10830 <sumMatrices+0x138>
   107b4:	e51b3010 	ldr	r3, [fp, #-16]
   107b8:	e1a03103 	lsl	r3, r3, #2
   107bc:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
   107c0:	e0823003 	add	r3, r2, r3
   107c4:	e5932000 	ldr	r2, [r3]
   107c8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   107cc:	e1a03103 	lsl	r3, r3, #2
   107d0:	e0823003 	add	r3, r2, r3
   107d4:	e5931000 	ldr	r1, [r3]
   107d8:	e51b3010 	ldr	r3, [fp, #-16]
   107dc:	e1a03103 	lsl	r3, r3, #2
   107e0:	e51b2024 	ldr	r2, [fp, #-36]	; 0xffffffdc
   107e4:	e0823003 	add	r3, r2, r3
   107e8:	e5932000 	ldr	r2, [r3]
   107ec:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   107f0:	e1a03103 	lsl	r3, r3, #2
   107f4:	e0823003 	add	r3, r2, r3
   107f8:	e5932000 	ldr	r2, [r3]
   107fc:	e51b3010 	ldr	r3, [fp, #-16]
   10800:	e1a03103 	lsl	r3, r3, #2
   10804:	e51b0018 	ldr	r0, [fp, #-24]	; 0xffffffe8
   10808:	e0803003 	add	r3, r0, r3
   1080c:	e5930000 	ldr	r0, [r3]
   10810:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   10814:	e1a03103 	lsl	r3, r3, #2
   10818:	e0803003 	add	r3, r0, r3
   1081c:	e0812002 	add	r2, r1, r2
   10820:	e5832000 	str	r2, [r3]
   10824:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   10828:	e2833001 	add	r3, r3, #1
   1082c:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
   10830:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
   10834:	e51b302c 	ldr	r3, [fp, #-44]	; 0xffffffd4
   10838:	e1520003 	cmp	r2, r3
   1083c:	baffffdc 	blt	107b4 <sumMatrices+0xbc>
   10840:	e51b3010 	ldr	r3, [fp, #-16]
   10844:	e2833001 	add	r3, r3, #1
   10848:	e50b3010 	str	r3, [fp, #-16]
   1084c:	e51b2010 	ldr	r2, [fp, #-16]
   10850:	e51b3028 	ldr	r3, [fp, #-40]	; 0xffffffd8
   10854:	e1520003 	cmp	r2, r3
   10858:	baffffbd 	blt	10754 <sumMatrices+0x5c>
   1085c:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
   10860:	e1a00003 	mov	r0, r3
   10864:	e24bd008 	sub	sp, fp, #8
   10868:	e8bd8810 	pop	{r4, fp, pc}
   1086c:	00010bb0 	.word	0x00010bb0

00010870 <main>:
   10870:	e92d4800 	push	{fp, lr}
   10874:	e28db004 	add	fp, sp, #4
   10878:	e24dd030 	sub	sp, sp, #48	; 0x30
   1087c:	e3a03003 	mov	r3, #3
   10880:	e50b3024 	str	r3, [fp, #-36]	; 0xffffffdc
   10884:	e3a03003 	mov	r3, #3
   10888:	e50b3028 	str	r3, [fp, #-40]	; 0xffffffd8
   1088c:	e51b1028 	ldr	r1, [fp, #-40]	; 0xffffffd8
   10890:	e51b0024 	ldr	r0, [fp, #-36]	; 0xffffffdc
   10894:	ebffff3a 	bl	10584 <generateRandomMatrix>
   10898:	e50b002c 	str	r0, [fp, #-44]	; 0xffffffd4
   1089c:	e51b1028 	ldr	r1, [fp, #-40]	; 0xffffffd8
   108a0:	e51b0024 	ldr	r0, [fp, #-36]	; 0xffffffdc
   108a4:	ebffff36 	bl	10584 <generateRandomMatrix>
   108a8:	e50b0030 	str	r0, [fp, #-48]	; 0xffffffd0
   108ac:	e59f027c 	ldr	r0, [pc, #636]	; 10b30 <main+0x2c0>
   108b0:	ebfffedc 	bl	10428 <puts@plt>
   108b4:	e3a03000 	mov	r3, #0
   108b8:	e50b3008 	str	r3, [fp, #-8]
   108bc:	ea00001a 	b	1092c <main+0xbc>
   108c0:	e3a03000 	mov	r3, #0
   108c4:	e50b300c 	str	r3, [fp, #-12]
   108c8:	ea00000e 	b	10908 <main+0x98>
   108cc:	e51b3008 	ldr	r3, [fp, #-8]
   108d0:	e1a03103 	lsl	r3, r3, #2
   108d4:	e51b202c 	ldr	r2, [fp, #-44]	; 0xffffffd4
   108d8:	e0823003 	add	r3, r2, r3
   108dc:	e5932000 	ldr	r2, [r3]
   108e0:	e51b300c 	ldr	r3, [fp, #-12]
   108e4:	e1a03103 	lsl	r3, r3, #2
   108e8:	e0823003 	add	r3, r2, r3
   108ec:	e5933000 	ldr	r3, [r3]
   108f0:	e1a01003 	mov	r1, r3
   108f4:	e59f0238 	ldr	r0, [pc, #568]	; 10b34 <main+0x2c4>
   108f8:	ebfffec1 	bl	10404 <printf@plt>
   108fc:	e51b300c 	ldr	r3, [fp, #-12]
   10900:	e2833001 	add	r3, r3, #1
   10904:	e50b300c 	str	r3, [fp, #-12]
   10908:	e51b200c 	ldr	r2, [fp, #-12]
   1090c:	e51b3028 	ldr	r3, [fp, #-40]	; 0xffffffd8
   10910:	e1520003 	cmp	r2, r3
   10914:	baffffec 	blt	108cc <main+0x5c>
   10918:	e3a0000a 	mov	r0, #10
   1091c:	ebfffed3 	bl	10470 <putchar@plt>
   10920:	e51b3008 	ldr	r3, [fp, #-8]
   10924:	e2833001 	add	r3, r3, #1
   10928:	e50b3008 	str	r3, [fp, #-8]
   1092c:	e51b2008 	ldr	r2, [fp, #-8]
   10930:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
   10934:	e1520003 	cmp	r2, r3
   10938:	baffffe0 	blt	108c0 <main+0x50>
   1093c:	e3a0000a 	mov	r0, #10
   10940:	ebfffeca 	bl	10470 <putchar@plt>
   10944:	e59f01ec 	ldr	r0, [pc, #492]	; 10b38 <main+0x2c8>
   10948:	ebfffeb6 	bl	10428 <puts@plt>
   1094c:	e3a03000 	mov	r3, #0
   10950:	e50b3010 	str	r3, [fp, #-16]
   10954:	ea00001a 	b	109c4 <main+0x154>
   10958:	e3a03000 	mov	r3, #0
   1095c:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
   10960:	ea00000e 	b	109a0 <main+0x130>
   10964:	e51b3010 	ldr	r3, [fp, #-16]
   10968:	e1a03103 	lsl	r3, r3, #2
   1096c:	e51b2030 	ldr	r2, [fp, #-48]	; 0xffffffd0
   10970:	e0823003 	add	r3, r2, r3
   10974:	e5932000 	ldr	r2, [r3]
   10978:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   1097c:	e1a03103 	lsl	r3, r3, #2
   10980:	e0823003 	add	r3, r2, r3
   10984:	e5933000 	ldr	r3, [r3]
   10988:	e1a01003 	mov	r1, r3
   1098c:	e59f01a0 	ldr	r0, [pc, #416]	; 10b34 <main+0x2c4>
   10990:	ebfffe9b 	bl	10404 <printf@plt>
   10994:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
   10998:	e2833001 	add	r3, r3, #1
   1099c:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
   109a0:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
   109a4:	e51b3028 	ldr	r3, [fp, #-40]	; 0xffffffd8
   109a8:	e1520003 	cmp	r2, r3
   109ac:	baffffec 	blt	10964 <main+0xf4>
   109b0:	e3a0000a 	mov	r0, #10
   109b4:	ebfffead 	bl	10470 <putchar@plt>
   109b8:	e51b3010 	ldr	r3, [fp, #-16]
   109bc:	e2833001 	add	r3, r3, #1
   109c0:	e50b3010 	str	r3, [fp, #-16]
   109c4:	e51b2010 	ldr	r2, [fp, #-16]
   109c8:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
   109cc:	e1520003 	cmp	r2, r3
   109d0:	baffffe0 	blt	10958 <main+0xe8>
   109d4:	e3a0000a 	mov	r0, #10
   109d8:	ebfffea4 	bl	10470 <putchar@plt>
   109dc:	e51b3028 	ldr	r3, [fp, #-40]	; 0xffffffd8
   109e0:	e51b2024 	ldr	r2, [fp, #-36]	; 0xffffffdc
   109e4:	e51b1030 	ldr	r1, [fp, #-48]	; 0xffffffd0
   109e8:	e51b002c 	ldr	r0, [fp, #-44]	; 0xffffffd4
   109ec:	ebffff41 	bl	106f8 <sumMatrices>
   109f0:	e50b0034 	str	r0, [fp, #-52]	; 0xffffffcc
   109f4:	e59f0140 	ldr	r0, [pc, #320]	; 10b3c <main+0x2cc>
   109f8:	ebfffe8a 	bl	10428 <puts@plt>
   109fc:	e3a03000 	mov	r3, #0
   10a00:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
   10a04:	ea00001a 	b	10a74 <main+0x204>
   10a08:	e3a03000 	mov	r3, #0
   10a0c:	e50b301c 	str	r3, [fp, #-28]	; 0xffffffe4
   10a10:	ea00000e 	b	10a50 <main+0x1e0>
   10a14:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
   10a18:	e1a03103 	lsl	r3, r3, #2
   10a1c:	e51b2034 	ldr	r2, [fp, #-52]	; 0xffffffcc
   10a20:	e0823003 	add	r3, r2, r3
   10a24:	e5932000 	ldr	r2, [r3]
   10a28:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
   10a2c:	e1a03103 	lsl	r3, r3, #2
   10a30:	e0823003 	add	r3, r2, r3
   10a34:	e5933000 	ldr	r3, [r3]
   10a38:	e1a01003 	mov	r1, r3
   10a3c:	e59f00f0 	ldr	r0, [pc, #240]	; 10b34 <main+0x2c4>
   10a40:	ebfffe6f 	bl	10404 <printf@plt>
   10a44:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
   10a48:	e2833001 	add	r3, r3, #1
   10a4c:	e50b301c 	str	r3, [fp, #-28]	; 0xffffffe4
   10a50:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
   10a54:	e51b3028 	ldr	r3, [fp, #-40]	; 0xffffffd8
   10a58:	e1520003 	cmp	r2, r3
   10a5c:	baffffec 	blt	10a14 <main+0x1a4>
   10a60:	e3a0000a 	mov	r0, #10
   10a64:	ebfffe81 	bl	10470 <putchar@plt>
   10a68:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
   10a6c:	e2833001 	add	r3, r3, #1
   10a70:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
   10a74:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
   10a78:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
   10a7c:	e1520003 	cmp	r2, r3
   10a80:	baffffe0 	blt	10a08 <main+0x198>
   10a84:	e3a0000a 	mov	r0, #10
   10a88:	ebfffe78 	bl	10470 <putchar@plt>
   10a8c:	e3a03000 	mov	r3, #0
   10a90:	e50b3020 	str	r3, [fp, #-32]	; 0xffffffe0
   10a94:	ea000017 	b	10af8 <main+0x288>
   10a98:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
   10a9c:	e1a03103 	lsl	r3, r3, #2
   10aa0:	e51b202c 	ldr	r2, [fp, #-44]	; 0xffffffd4
   10aa4:	e0823003 	add	r3, r2, r3
   10aa8:	e5933000 	ldr	r3, [r3]
   10aac:	e1a00003 	mov	r0, r3
   10ab0:	ebfffe56 	bl	10410 <free@plt>
   10ab4:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
   10ab8:	e1a03103 	lsl	r3, r3, #2
   10abc:	e51b2030 	ldr	r2, [fp, #-48]	; 0xffffffd0
   10ac0:	e0823003 	add	r3, r2, r3
   10ac4:	e5933000 	ldr	r3, [r3]
   10ac8:	e1a00003 	mov	r0, r3
   10acc:	ebfffe4f 	bl	10410 <free@plt>
   10ad0:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
   10ad4:	e1a03103 	lsl	r3, r3, #2
   10ad8:	e51b2034 	ldr	r2, [fp, #-52]	; 0xffffffcc
   10adc:	e0823003 	add	r3, r2, r3
   10ae0:	e5933000 	ldr	r3, [r3]
   10ae4:	e1a00003 	mov	r0, r3
   10ae8:	ebfffe48 	bl	10410 <free@plt>
   10aec:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
   10af0:	e2833001 	add	r3, r3, #1
   10af4:	e50b3020 	str	r3, [fp, #-32]	; 0xffffffe0
   10af8:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
   10afc:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
   10b00:	e1520003 	cmp	r2, r3
   10b04:	baffffe3 	blt	10a98 <main+0x228>
   10b08:	e51b002c 	ldr	r0, [fp, #-44]	; 0xffffffd4
   10b0c:	ebfffe3f 	bl	10410 <free@plt>
   10b10:	e51b0030 	ldr	r0, [fp, #-48]	; 0xffffffd0
   10b14:	ebfffe3d 	bl	10410 <free@plt>
   10b18:	e51b0034 	ldr	r0, [fp, #-52]	; 0xffffffcc
   10b1c:	ebfffe3b 	bl	10410 <free@plt>
   10b20:	e3a03000 	mov	r3, #0
   10b24:	e1a00003 	mov	r0, r3
   10b28:	e24bd004 	sub	sp, fp, #4
   10b2c:	e8bd8800 	pop	{fp, pc}
   10b30:	00010bcc 	.word	0x00010bcc
   10b34:	00010bd8 	.word	0x00010bd8
   10b38:	00010bdc 	.word	0x00010bdc
   10b3c:	00010be8 	.word	0x00010be8

00010b40 <__libc_csu_init>:
   10b40:	e92d47f0 	push	{r4, r5, r6, r7, r8, r9, sl, lr}
   10b44:	e1a07000 	mov	r7, r0
   10b48:	e59f6048 	ldr	r6, [pc, #72]	; 10b98 <__libc_csu_init+0x58>
   10b4c:	e59f5048 	ldr	r5, [pc, #72]	; 10b9c <__libc_csu_init+0x5c>
   10b50:	e08f6006 	add	r6, pc, r6
   10b54:	e08f5005 	add	r5, pc, r5
   10b58:	e0466005 	sub	r6, r6, r5
   10b5c:	e1a08001 	mov	r8, r1
   10b60:	e1a09002 	mov	r9, r2
   10b64:	ebfffe1e 	bl	103e4 <_init>
   10b68:	e1b06146 	asrs	r6, r6, #2
   10b6c:	08bd87f0 	popeq	{r4, r5, r6, r7, r8, r9, sl, pc}
   10b70:	e3a04000 	mov	r4, #0
   10b74:	e2844001 	add	r4, r4, #1
   10b78:	e4953004 	ldr	r3, [r5], #4
   10b7c:	e1a02009 	mov	r2, r9
   10b80:	e1a01008 	mov	r1, r8
   10b84:	e1a00007 	mov	r0, r7
   10b88:	e12fff33 	blx	r3
   10b8c:	e1560004 	cmp	r6, r4
   10b90:	1afffff7 	bne	10b74 <__libc_csu_init+0x34>
   10b94:	e8bd87f0 	pop	{r4, r5, r6, r7, r8, r9, sl, pc}
   10b98:	000103bc 	.word	0x000103bc
   10b9c:	000103b4 	.word	0x000103b4

00010ba0 <__libc_csu_fini>:
   10ba0:	e12fff1e 	bx	lr

Disassembly of section .fini:

00010ba4 <_fini>:
   10ba4:	e92d4008 	push	{r3, lr}
   10ba8:	e8bd8008 	pop	{r3, pc}
