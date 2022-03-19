/* 	stratup_cortexM3.s
	Mhamed_Abdallah
*/

.section .vectors

.word 0x20001000
.word _reset			/* 1 reset*/
.word _vector_handler	/* 2 _NMI_handler*/
.word _vector_handler	/* 3 _HARD_FAULT_handler*/
.word _vector_handler	/* 4 memory mangment*/
.word _vector_handler	/* 5 bus fault*/
.word _vector_handler	/* 6 usage fault*/


.section .text
_reset:
	bl main
	b .
.thumb_func	
_vector_handler:
	b _reset