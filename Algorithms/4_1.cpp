/***********************************************************************
* 					Soldatov A.K. APO-13                               *
*						Task 4_1                                       *
***********************************************************************/
#include <iostream>

class CQueue {
public:
	CQueue(int size);
	~CQueue() { delete[] buffer; }
	void Enqueue(int a);
	int Dequeue();
private:
	int* buffer;
	int bufferSize;
	int head; // Указывает на первый элемент очереди.
	int tail; // Указывает на следующий после последнего.
	int realSize; // количество реально занятых элементов в buffer
};

CQueue::CQueue(int size) : // инициализация переменных в конструкторе
bufferSize(size),
head(0),
tail(0),
realSize(0)
{
	buffer = new int[bufferSize]; // Создаем буфер.
}
// Добавление элемента.
void CQueue::Enqueue(int a)
{
	if ( realSize == bufferSize)		// расширять буффер нужно только если все элементы в буфере заняты
	{
		int *temp = new int[bufferSize<<1];
		int tp = head;
		for (int i = (bufferSize << 1) - (bufferSize - head), j = 0; i < (bufferSize << 1); ++i, ++j) // копируем старые элементы в новый массив:
		{
			temp[i] = buffer[head+j];																	// все, что после head,- вправо
		}
		head = (bufferSize << 1) - (bufferSize - head);
		memcpy(temp,buffr,head);
		tail = tp;
		delete[] buffer;
		bufferSize <<= 1;
		buffer = temp;
	} 
	buffer[tail] = a;
	tail = (tail + 1) % bufferSize;																		// очередь зацикливается
	realSize++;
}
// Извлечение элемента.
int CQueue::Dequeue()
{
	if (realSize)
	{
		int result = buffer[head];
		head = (head + 1) % bufferSize;		// очередь зацикливается
		realSize--;
		return result;
	}
	else return -1;
}

int main()
{
	int counter = 0;
	int curr = 0;
	std::cin >> counter;
	CQueue q(2);
	for (int i = 0; i < (counter<<1); ++i)
	{
		std::cin >> curr;
		switch (curr)
		{
		case 3:
			std::cin >> curr;
			q.Enqueue(curr);
			i++;
			break;
		case 2:
			std::cin >> curr;
			if (q.Dequeue() == curr)
			{
				i++;
				continue;
			}
			else
			{
				std::cout << "NO";
				return 0;
			}
		}
	}
	std::cout << "YES";
	return 0;
}
