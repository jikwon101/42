#include <unistd.h> //write
#include <stdio.h> //FILE 구조체, fopen, fscanf, fclose
#include <stdlib.h> //malloc, free
#include <string.h> //memset
#define ERR1 "Error: argument\n"
#define ERR2 "Error: Operation file corrupted\n"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_perror(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

//현재 좌표가 사각형의 외부인지, 경계인지, 외부인지 판단하는 함수
int check_boundary(float x, float y, float rec_x, float rec_y, float rec_width, float rec_height)
{
	if (x < rec_x || x > rec_x + rec_width || y < rec_y || y > rec_y + rec_height)
		return (0);		// 좌표 (x, y)는 사각형 바깥이다.
	else if (x - rec_x < 1.0000000 || (rec_x + rec_width) - x < 1.0000000 ||
			y - rec_y < 1.000000 || (rec_y + rec_height) - y < 1.0000000)
		return (1);		// 좌표 (x, y)는 사각형 경계선이다.
	return (2);			// 좌표 (x, y)는 사각형 내부이다. 
}

int main(int argc, char *argv[])
{
	FILE	*file;
	char	*paper;
	int		bg_width;
	int		bg_height;
	char	bg_ch;

	int		read;
	int		x, y;
	int		pos;

	char	rec_type;
	float	rec_x;		//사각형 시작 x좌표
	float	rec_y;		//사각현 시작 y좌표
	float	rec_width;
	float	rec_height;
	char	rec_color;

	if(argc != 2)
		return (ft_perror(ERR1));
	//에러처리
	if(!(file = fopen(argv[1], "r")) ||
		(fscanf(file, "%d %d %c\n", &bg_width, &bg_height, &bg_ch) != 3) ||
		!(bg_width > 0 && bg_width <= 300 && bg_height > 0 && bg_height <= 300) ||
		!(paper = (char *)malloc(sizeof(char) * bg_width * bg_height)))
		return (ft_perror(ERR2));
	//배경그리기
	memset(paper, bg_ch, bg_width * bg_height);

	//파일의 두번째 줄부터 입력 형식에 부합하면 반복
	while((read = fscanf(file, "%c %f %f %f %f %c\n", &rec_type, &rec_x, &rec_y, &rec_width, &rec_height, &rec_color)) == 6)
	{
		if(!(rec_width > 0 && rec_height > 0) || !(rec_type == 'r' || rec_type == 'R'))
			break;
		y = 0;
		while (y < bg_height)
		{
			x = 0;
			while (x < bg_width)
			{
				pos = check_boundary((float)x, (float)y, rec_x, rec_y, rec_width, rec_height);
				if (pos == 1 || (pos == 2 && rec_type == 'R'))
					paper[y * bg_width + x] = rec_color;
				x++;
			}
			y++;
		}
	}

	if (read != -1)	//반복문을 탈출했는데 그 이유가 읽기 실패가 아니라면, line의 입력형식이 잘못된 것이기 때문에
	{
		free(paper);
		return (ft_perror(ERR2));
	}

	y = 0;
	while (y < bg_height)
	{
		write(1, paper + y * bg_width, bg_width);
		write(1, "\n", 1);
		y++;
	}
	free(paper);
	fclose(file);

	return (0);
}
