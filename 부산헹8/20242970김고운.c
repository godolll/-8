#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

// 파라미터
#define LEN_MIN 15   //기차 길이
#define LEN_MAX 50
#define STM_MIN 0    //마동석 체력
#define STM_MAX 5
#define PROB_MIN 10  //확률
#define PROB_MAX 90
#define AGGRO_MIN 0  //어그로 범위
#define AGGRO_MAX 5  

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// 마동석 행동
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

	// 기차 길이
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


	// 마동석 체력
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

	// 확률
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
		for (i = 0; i < length; i++) { // 1번째 줄
			printf("#");
		}
		printf("\n");


		for (i = 0; i < length; i++) { // 2번째 줄
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


		for (i = 0; i < length; i++) { // 3번째 줄
			printf("#");
		}
		printf("\n\n\n");


	}
	// 변수 선언 
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
		

		// 열차
		for (i = 0; i < length; i++) { // 1번째 줄
			printf("#");
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 2번째 줄
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

		for (i = 0; i < length; i++) { // 3번째 줄
			printf("#");
		}
		printf("\n\n\n");




		// 시민 상태 출력
		if (C != bC) {
			printf("citizen: %d -> %d (aggro: %d -> %d)\n", bC, C, bCA, citizen_aggro);
		}
		else if (C == bC) {
			printf("citizen: stay %d (aggro: %d -> %d)\n", bC, bCA, citizen_aggro);
		}
		bC = C;
		bCA = citizen_aggro;

		// 좀비 상태 출력
		if (madongseok_action_number == 1) { // 붙들기 성공 - 좀비 이동 X
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


		// 마동석 상태 입력
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

		// 마동석 이동
		if (move == 1) {
			M--;
			madongseok_aggro++;  
			if (madongseok_aggro > AGGRO_MAX) madongseok_aggro = AGGRO_MAX;      
		}
		else {
			madongseok_aggro--;  
			if (madongseok_aggro < AGGRO_MIN) madongseok_aggro = AGGRO_MIN;  
		}

		// 열차
		for (i = 0; i < length; i++) { // 1번째 줄
			printf("#");
		}
		printf("\n");

		for (i = 0; i < length; i++) { // 2번째 줄
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

		for (i = 0; i < length; i++) { // 3번째 줄
			printf("#");
		}
		printf("\n\n\n");

	
		// 마동석 위치 출력 
		if (M != bM) {
			printf("madongseok: %d -> %d(aggro: %d -> %d, stamina: %d)", bM, M, bMA, madongseok_aggro, stm);
		}
		else if (M == bM) {
			printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)", bM, bMA, madongseok_aggro, stm);
		}
		bM = M;
		bMA = madongseok_aggro;
		printf("\n\n\n");


		// 시민 행동
		if (C == 1) {
			printf("YOU WIN!...");
			break;
		}
		else { 
			printf("citizen does nothing.\n");
		}
		int bS = stm;
		// <좀비 공격> 둘다 인접
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
		// <좀비 공격> 시민만 인접
		else if (Z == (C + 1)) {
			printf("GAME OEVER! citizen dead...\n");
			break;
		}
		// <좀비 공격> 마동석만 인접
		else if (Z == (M - 1)) {
			stm--;
			printf("Zombie attacked madongseok (stamina: %d -> %d)\n", bS, stm);
		}
		// 둘 다 인접 X
		else {
			printf("zombie attacked nobody.\n");
		}
		// 마동석 사망
		if (stm == STM_MIN) {
			printf("GAME OVER! madongseok dead...\n");
			break;
		}
		bS = stm;

		// 마동석 행동
		int madongseok_action;
		if (M != (Z +1)) {  // 인접하지 않은 경우
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
		else if (M == (Z + 1)) {  // 인접한 경우
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

				if (madongseok <= (100 - prob)) { //성공
					printf("madongseok pulled zombie... Next turn, it can't move\n");
					printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, bMA, madongseok_aggro, bS, stm);
					madongseok_action_number = 1;
				}
				else {  // 실패
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















