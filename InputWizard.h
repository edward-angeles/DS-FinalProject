#pragma once
#include <stdio.h>


class InputWizard {
public:
	static void GetCharNoBuffer(const char* prompt, char* choice) { 
		printf("%s", prompt);
		scanf("%c%*c", choice);
	}

	static void GetIntNoBuffer(const char* prompt, int* choice) {
		printf("%s", prompt);
		scanf("%d%*c", choice);
	}

	static void GetBufferedInput(const char* prompt, char* buffer) {
		printf("%s", prompt);
		fgets(buffer, sizeof buffer, stdin);
	}
};