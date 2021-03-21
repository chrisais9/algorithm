#include <stdio.h>

#define STUDENT_SIZE 70

struct score
{
    int attendance;   // 출석점수
    int midterm_exam; // 중간고사점수
    int final_exam;   // 기말고사점수
    int assignment;   // 숙제점수
};

struct student
{
    int valid;           // 성적입력여부
    int student_id;      // 학번
    struct score *score; // 학생성적
};

void insert_score(struct student *student_list, struct score *score_list);
void invalidate_score(struct student *student_list);
void print_score(struct student student_list);

int main(void)
{
    struct student student_list[STUDENT_SIZE] = {{0, 0, NULL}};
    struct score score_list[STUDENT_SIZE] = {{0, 0, 0, 0}};
    int number, menu;
    
    while (1)
    {
        printf("1. 성적 입력 또는 수정\t2. 성적 삭제\t3. 성적 출력\t4. 종료\n메뉴를 입력하시오: ");
        scanf("%d", &menu);
        
        switch (menu)
        {
            case 1:
                insert_score(student_list, score_list);
                break;
            case 2:
                invalidate_score(student_list);
                break;
            case 3:
                //print_score(student_list);
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
    
    return 0;
}

void insert_score(struct student *student_list, struct score *score_list)
{
    int a=-1, b=-1, c=-1, d=-1,x=-1;
    while (x > 70 || x < 1) {
        printf("학생의 일련번호를 입력하시오(1-70):");
        scanf("%d", &x);
    }
    printf("학번을 입력해주세요. 예) 20190001 : ");
    scanf("%d", &student_list[x].student_id);
    while (a > 10 || a < 0 || b>40 || b < 0 || c>40 || c < 0 || d>10 || d < 0) {
        printf("출석점수 (0-10), 중간고사점수 (0-40), 기말고사점수(0-40), 숙제점수(0-10)를 입력하시오 : ");
        scanf("%d %d %d %d", &a, &b, &c, &d);
    }
    student_list[x].score->attendance = a;
    student_list[x].score->midterm_exam = b;
    student_list[x].score->final_exam = c;
    student_list[x].score->assignment = d;
    printf("\n");
    printf("일련번호 %d 학생의 성적이 입력 또는 수정 되었습니다.\n", x);
    printf("\n");
}

void invalidate_score(struct student *student_list)
{
    int x = -1;
    
    while (x > 70 || x < 1) {
        printf("학생의 일련번호를 입력하시오(1-70):");
        scanf("%d", &x);
    }
    student_list[x].valid = 0;
    
    printf("\n");
    printf("일련번호 %d 학생의 성적이 삭제 되었습니다.\n", x);
    printf("\n");
}

void print_score(struct student *student_list)
{
    printf("==================성적출력==================");
    for (int i = 0; i < STUDENT_SIZE; i++) {
        if (student_list[i].valid == 1) {
            printf("일련번호 %d\t 학번 : %d\t 출석점수 : %d\t 중간점수 : %d\t 기말점수 : %d\t 숙제점수 : %d\t\n", i,student_list->student_id ,student_list[i].score->attendance,student_list[i].score->midterm_exam,student_list[i].score->final_exam,student_list[i].score->assignment);
        }
    }
}
