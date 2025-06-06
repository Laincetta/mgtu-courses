#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


//0
int countStrings(FILE* file)
{
	int count = 0;
	char tempString[40];
	while (fgets(tempString, 40, file)) count++;
	rewind(file);
	return count;
}

//0
void inputStudent(FILE* file, int n, char** surname, char** name, int* group, int** mark)
{
	for (int i = 0; i < n; i++)
	{
		fscanf(file, " %s", surname[i]);
		fscanf(file, " %s", name[i]);
		fscanf(file, " %d", &group[i]);
		for (int j = 0; j < 4; j++) fscanf(file, " %d", &mark[i][j]);
	}
}

//0
void outputStudent(FILE* file, int n, char** surname, char** name, int* group, int** mark)
{
	printf("\nФамилия/Имя/Группа/Оценки за сессию\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s ", surname[i]);
		printf("%s ", name[i]);
		printf("%d ", group[i]);
		for (int j = 0; j < 4; j++) printf("%d ", mark[i][j]);
		printf("\n");
	}
}

//1
bool ifStudentHas2(int** mark, int curI)
{
	bool ifHas2 = false;
	for (int j = 0; j < 4; j++)
	{
		if (mark[curI][j] == 2)
		{
			ifHas2 = true;
		}
	}
	return ifHas2;
}

//1
int countStudentsWithout2(int** mark, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!ifStudentHas2(mark, i)) count++;
	}
	return count;
}

//1
void inputStudentsWithout2(char** nameSurnameIfPassed, char** name, char** surname, int** mark, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (!ifStudentHas2(mark, i))
		{
			strcat(nameSurnameIfPassed[j], surname[i]);
			strcat(nameSurnameIfPassed[j], " ");
			strcat(nameSurnameIfPassed[j], name[i]);
			j++;
		}
	}
}

//1
void ouputStudentsWithout2(char** namePassed, int n1)
{
	for (int i = 0; i < n1; i++)
	{
		printf("\n%s", namePassed[i]);
	}
}

//1
void writeStudentsWithout2ToFile(FILE* students_without_2, char** namePassed, int n1)
{
	for (int i = 0; i < n1; i++)
	{
		fprintf(students_without_2, "%s\n", namePassed[i]);
	}
}

//2
int countStudentsGroup(int* group, int curGroup, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (group[i] == curGroup) count++;
	}
	return count;
}

//2
void inputStudentsGroup(int* studentCurGroup, int curGroup, int* group, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (group[i] == curGroup)
		{
			studentCurGroup[j] = i;
			j++;
		}
	}
}

//2
void outputStudentsGroup(int* studentCurGroup, int n2, char** surname, char** name, int* group, int** mark)
{
	for (int i = 0; i < n2; i++)
	{
		int ind = studentCurGroup[i];
		printf("\n%s ", surname[ind]);
		printf("%s ", name[ind]);
		printf("%d ", group[ind]);
		for (int j = 0; j < 4; j++) printf("%d ", mark[ind][j]);
	}
}

//3
bool ifStudentHas2or3(int** mark, int curI)
{
	bool ifHas23 = false;
	for (int j = 0; j < 4; j++)
	{
		if (mark[curI][j] == 2 || mark[curI][j] == 3)
		{
			ifHas23 = true;
		}
	}
	return ifHas23;
}

//3
int countStudents45Only(int** mark, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!ifStudentHas2or3(mark, i)) count++;
	}
	return count;
}

//3
void inputStudents45Only(int** mark, int* students45Only, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (!ifStudentHas2or3(mark, i))
		{
			students45Only[j] = i;
			j++;
		}
	}
}

//3
void outputStudents45Only(int* students45Only, int n3, char** surname, char** name, int* group, int** mark)
{
	for (int i = 0; i < n3; i++)
	{
		printf("\n%s ", surname[students45Only[i]]);
		printf("%s ", name[students45Only[i]]);
		printf("%d ", group[students45Only[i]]);
		for (int j = 0; j < 4; j++) printf("%d ", mark[students45Only[i]][j]);
	}
}

//4
double getMaxPoint(int** mark, int n)
{
	double max = (mark[0][0] + mark[0][1] + mark[0][2] + mark[0][3]) / 4.;
	for (int i = 1; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < 4; j++)
		{
			sum += mark[i][j];
		}
		if (sum / 4. > max) max = sum / 4.;
	}
	return max;
}


int main()
{
	//0: чтение данных с файла, первостепенная обработка, вывод
	char* fileName = new char[20];
	printf("Введите имя открываемого файла: ");
	scanf("%s", fileName);
	FILE* studentList = fopen(fileName, "r");
	while (!studentList)
	{
		printf("Ошибка открытия файла\n");
		printf("\nВведите имя открываемого файла: ");
		scanf(" %s", fileName);
		studentList = fopen(fileName, "r");
	}

	int n = countStrings(studentList);
	printf("\nКоличество строк (студентов): %d", n);

	char** surname = new char* [n];
	for (int i = 0; i < n; i++)
	{
		surname[i] = new char[20];
	}

	char** name = new char* [n];
	for (int i = 0; i < n; i++)
	{
		name[i] = new char[20];
	}

	int* group = new int[n];

	int** mark = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mark[i] = new int[4];
	}

	inputStudent(studentList, n, surname, name, group, mark);

	printf("\nСписок студентов: ");
	outputStudent(studentList, n, surname, name, group, mark);

	//1: Вывести на экран и записать в новый файл имена студентов без двоек
	FILE* fStudentsWithout2 = fopen("students_without_2.txt", "w");
	printf("\n(1)Студенты сдавшие сессию: ");
	int n1 = countStudentsWithout2(mark, n);
	if (n1 == 0) printf("\nНи один студент не сдал сессию");
	else
	{
		char** arrStudentsWithout2 = new char* [n1];
		for (int i = 0; i < n1; i++)
		{
			arrStudentsWithout2[i] = new char[40]();
		}
		inputStudentsWithout2(arrStudentsWithout2, name, surname, mark, n);
		writeStudentsWithout2ToFile(fStudentsWithout2, arrStudentsWithout2, n1);
		ouputStudentsWithout2(arrStudentsWithout2, n1);
	}


	//2: Пользователь вводит с клавиатуры номер группы, вывести всю информацию о студентах, которые учатся в этой группе
	int checkGroup;
	printf("\n\n(2)Введите номер группы для проверки информации о ней: ");
	scanf(" %d", &checkGroup);
	int n2 = countStudentsGroup(group, checkGroup, n);
	if (n2 == 0) printf("\nТаких групп нет");
	else
	{
		int* studentsCurGroup = new int[n2];
		inputStudentsGroup(studentsCurGroup, checkGroup, group, n);
		outputStudentsGroup(studentsCurGroup, n2, surname, name, group, mark);
	}


	//3: Вывести на экран всю информацию о студентах, у которых за сессию только четверки и пятерки
	printf("\n\n(3)Студенты сдавшие сессию на хорошо или отлично: ");
	int n3 = countStudents45Only(mark, n);
	if (n3 == 0) printf("Таких cтудентов нет");
	else
	{
		int* students45Only = new int[n3];
		inputStudents45Only(mark, students45Only, n);
		outputStudents45Only(students45Only, n3, surname, name, group, mark);
	}

	//4: Найти максимальный средний балл студентов
	double maxPoint = getMaxPoint(mark, n);
	printf("\n\n(4)Максимальный балл среди студентов:\n%.2lf\n", maxPoint);


	getchar();
}