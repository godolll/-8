#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

// �Ķ����
#define LEN_MIN 15   //���� ����
#define LEN_MAX 50
#define STM_MIN 0    //������ ü��
#define STM_MAX 5
#define PROB_MIN 10  //Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0  //��׷� ����
#define AGGRO_MAX 5  

// ������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

// ������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// ������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2



int main(void) {
	srand((unsigned int)time(NULL));

	printf("     --------    ------\n");
	printf("            +    |      +\n");
	printf("          +      |    +\n");
	printf("        +        |    +\n");
	printf("      +          |      +\n");
	printf("     --------    ------\n");
	printf(" \n\n\n");
	Sleep(2000);

	// ���� ����
	int length;
	do {
		printf("train length(%d~%d)>> ", LEN_MIN, LEN_MAX);
		if (scanf_s("%d", &length) != 1) {
			while (getchar() != '\n');
			continue;
		}
		if (length < LEN_MIN || length > LEN_MAX) {
			continue;
		}
		break;
	} while (1);


	// ������ ü��
	int stm;
	do {
		printf("madongseok stamina(%d~%d)>> ", STM_MIN, STM_MAX);
		if (scanf_s("%d", &stm) != 1) {
			while (getchar() != '\n');
			continue;
		}
		if (stm < STM_MIN || stm > STM_MAX) {
			continue;
		}
		break;
	} while (1);

	// Ȯ��
	int prob;
	do {
		printf("percentile probability 'p'(%d~%d)>> ", PROB_MIN, PROB_MAX);
		if (scanf_s("%d", &prob) != 1) {
			while (getchar() != '\n');
			continue;
		}
		if (prob < PROB_MIN || prob > PROB_MAX) {
			continue;
		}
		break;
	} while (1);
	printf("\n\n");



	if (length >= LEN_MIN && length <= LEN_MAX) {
		if (prob >= PROB_MIN && prob <= PROB_MAX);
		int i;
		for (i = 0; i < length; i++) { // 1��° ��
			printf("#");
		}
		printf("\n");


		for (i = 0; i < length; i++) { // 2��° ��
			if (i == 0) {
				printf("#");
			}

			else if (i == (length - 1)) {
				printf("#");
			}

			else if (i == (length - 2)) {
				printf("M");
			}

			else if (i == (length - 3)) {
				printf("Z");
			}

			else if (i == (length - 6)) {
				printf("C");
			}

			else {
				printf(" ");
			}
		}
		printf("\n");


		for (i = 0; i < length; i++) { // 3��° ��
			printf("#");
		}
		printf("\n\n\n");


	}
	// ���� ���� 
	int C = length - 6;
	int Z = length - 3;
	int M = length - 2;
	int bC = C;
	int bZ = Z;
	int bM = M;
	int i;
	int turn = 0;
	int move;
	int madongseok_action_number = 0;

	int citizen_aggro = 1;
	int bCA = citizen_aggro;

	int madongseok_aggro = 1;
	int bMA = madongseok_aggro;

	while (1) {
		turn++;
		int citizen = rand() % 100;
		int zombie = rand() % 100;
		int madongseok = rand() % 100;

		if (citizen <= (100 - prob)) {
			C--;
			citizen_aggro++; 
			if (citizen_aggro > AGGRO_MAX) citizen_aggro = AGGRO_MAX; 
		}
		else {
			citizen_aggro--; 
			if (citizen_aggro < AGGRO_MIN) citizen_aggro = AGGRO_MIN; 
		}

		if (turn % 2 != 0 && madongseok_action_number == 0) {
			if (zombie <= prob) {
				Z--;
			}
		}
		

		// ����
		for (i = 0; i < length; i++) { // 1��° ��
			printf("#");
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 2��° ��
			if (i == 0) {
				printf("#");
			}

			else if (i == (length - 1)) {
				printf("#");
			}

			else if (i == M) {
				printf("M");
			}

			else if (i == Z) {
				printf("Z");
			}

			else if (i == C) {
				printf("C");
			}

			else {
				printf(" ");
			}
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 3��° ��
			printf("#");
		}
		printf("\n\n\n");




		// �ù� ���� ���
		if (C != bC) {
			printf("citizen: %d -> %d (aggro: %d -> %d)\n", bC, C, bCA, citizen_aggro);
		}
		else if (C == bC) {
			printf("citizen: stay %d (aggro: %d -> %d)\n", bC, bCA, citizen_aggro);
		}
		bC = C;
		bCA = citizen_aggro;

		// ���� ���� ���
		if (madongseok_action_number == 1) { // �ٵ�� ���� - ���� �̵� X
			printf("zombie: stay %d (madongseok pulled zombie)\n", bZ);
		}
		else {
			if (Z != bZ) {
				printf("zombie: %d -> %d\n", bZ, Z);
			}
			else {
				if (turn % 2 == 1) {
					printf("zombie: stay %d\n", bZ);
				}
				else {
					printf("zombie: stay %d (cannot move)\n", bZ);
				}
			}
		}
		bZ = Z;
		printf("\n\n");


		// ������ ���� �Է�
		while (1) {
			if (M == (Z + 1)) {
				printf("madongseok move(0:stay)>> ");
				scanf_s("%d", &move);
				if (move == 0) {
					break;
				}
			}
			else {
				printf("madongseok move(0:stay, 1:left)>> ");
				scanf_s("%d", &move);
				if (move == 1 || move == 0) {
					break;
				}
			}
		}

		// ������ �̵�
		if (move == 1) {
			M--;
			madongseok_aggro++;  
			if (madongseok_aggro > AGGRO_MAX) madongseok_aggro = AGGRO_MAX;      
		}
		else {
			madongseok_aggro--;  
			if (madongseok_aggro < AGGRO_MIN) madongseok_aggro = AGGRO_MIN;  
		}

		// ����
		for (i = 0; i < length; i++) { // 1��° ��
			printf("#");
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 2��° ��
			if (i == 0) {
				printf("#");
			}

			else if (i == (length - 1)) {
				printf("#");
			}

			else if (i == M) {
				printf("M");
			}

			else if (i == Z) {
				printf("Z");
			}

			else if (i == C) {
				printf("C");
			}

			else {
				printf(" ");
			}
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 3��° ��
			printf("#");
		}
		printf("\n\n\n");

	
		// ������ ��ġ ��� 
		if (M != bM) {
			printf("madongseok: %d -> %d(aggro: %d -> %d, stamina: %d)", bM, M, bMA, madongseok_aggro, stm);
		}
		else if (M == bM) {
			printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)", bM, bMA, madongseok_aggro, stm);
		}
		bM = M;
		bMA = madongseok_aggro;
		printf("\n\n\n");


		// �ù� �ൿ
		if (C == 1) {
			printf("YOU WIN!...");
			break;
		}
		else { 
			printf("citizen does nothing.\n");
		}
		int bS = stm;
		// <���� ����> �Ѵ� ����
		if (Z == (C + 1) && Z == (M - 1)) {
			if (citizen_aggro > madongseok_aggro) {
				printf("GAME OEVER! citizen dead...\n");
				break;
			}
			else {
				stm--;
				printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n", citizen_aggro, madongseok_aggro, bS, stm);
			}
		}
		// <���� ����> �ùθ� ����
		else if (Z == (C + 1)) {
			printf("GAME OEVER! citizen dead...\n");
			break;
		}
		// <���� ����> �������� ����
		else if (Z == (M - 1)) {
			stm--;
			printf("Zombie attacked madongseok (stamina: %d -> %d)\n", bS, stm);
		}
		// �� �� ���� X
		else {
			printf("zombie attacked nobody.\n");
		}
		// ������ ���
		if (stm == STM_MIN) {
			printf("GAME OVER! madongseok dead...\n");
			break;
		}
		bS = stm;

		// ������ �ൿ
		int madongseok_action;
		if (M != (Z +1)) {  // �������� ���� ���
			while (1) {
				printf("madongseok action(0.rest, 1.provoke)>> ");
				scanf_s("%d", &madongseok_action);
				if (madongseok_action == 0 || madongseok_action == 1) {
					break;
				}
			}
			printf("\n\n");
			if (madongseok_action == 0) {
				printf("madongseok rests...\n");
				madongseok_aggro--;
				stm++;
				if (AGGRO_MIN > madongseok_aggro) madongseok_aggro = AGGRO_MIN;
				if (STM_MAX < stm) stm = STM_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, bMA, madongseok_aggro, bS, stm);
			}
			else if (madongseok_action == 1) {
				printf("madongseok provoked zombie...\n\n");
				madongseok_aggro = AGGRO_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, bMA, madongseok_aggro, bS);
			}
		} 
		else if (M == (Z + 1)) {  // ������ ���
			while (1) {
				printf("madongseok action(0.rest, 1.provoke, 2. pull)>> ");
				scanf_s("%d", &madongseok_action);
				if (madongseok_action == 0 || madongseok_action == 1 || madongseok_action == 2) {
					break;
				}
			}
			printf("\n\n");
			if (madongseok_action == 0) {
				printf("madongseok rests...\n");
				madongseok_aggro--;
				stm++;
				if (madongseok_aggro < AGGRO_MIN) madongseok_aggro = AGGRO_MIN;
				if (stm > STM_MAX) stm = STM_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, bMA, madongseok_aggro, bS, stm);
			}
			else if (madongseok_action == 1) {
				printf("madongseok provoked zombie...\n");
				madongseok_aggro = STM_MAX;
				printf("madongseok: %d (aggro: %d -> %d, stamina: %d)\n", M, bMA, madongseok_aggro, bS);
			}
			else if (madongseok_action == 2) {
				madongseok_aggro += 2; 
				stm--; 
				if (madongseok_aggro > AGGRO_MAX) madongseok_aggro = AGGRO_MAX;
				if (stm < STM_MIN) stm = STM_MIN;

				if (madongseok <= (100 - prob)) { //����
					printf("madongseok pulled zombie... Next turn, it can't move\n");
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, bMA, madongseok_aggro, bS, stm);
					madongseok_action_number = 1;
				}
				else {  // ����
					printf("madongseok failed to pull zombie\n");
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, bMA, madongseok_aggro, bS, stm);
				}
			}
		}
		printf("\n\n\n");

		if (stm == STM_MIN) {
			break;
		}
		bMA = madongseok_aggro;  
		bS = stm; 
	}

	return 0;
}















