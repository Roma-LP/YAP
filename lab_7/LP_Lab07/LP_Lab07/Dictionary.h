#pragma once
#include<cstring>
#define DICTNAMEMAXSIZE  20  // максимальный размер имени словар€
#define DICTMAXSIZE      100 // максимальна€ емкость словар€
#define ENTRYNAMEMAXSIZE 30  // максимальна€ длина имени в словаре
#define THROW01 "Create: превышен размер имени словар€"
#define THROW02 "Create: превышен максимальной емкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04 "AddEntry: дублироваание идентификатора"
#define THROW05 "DelEntry: не найден элемент"
#define THROW06 "GetEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary {

	struct Entry			// элемент словар€
	{					
		int id;						 // идентификатор (уникальный)
		char name[ENTRYNAMEMAXSIZE]; // символьна€ ифнормаци€
	};

	struct Instance   // экзэмпл€р словар€
	{				
		char name[DICTNAMEMAXSIZE];    // наименование словар€
		int maxsize;	   // максимальна€ емкость словар€
		int size;					   // текущий размер словар€ < DICTNAMEMAXSIZE
		Entry dictionary[DICTMAXSIZE]; // массив элементов словар€
	};

	Instance Create(				// создать словарь
		const char name[DICTNAMEMAXSIZE],	// им€ словар€
		int size					// емкость словар€ < DICTNAMEMAXSIZE
		);					

	void AddEntry(		// добавить элемент в словарь
		Instance &inst, // экзмемпл€р словар€
		Entry ed		// идентификатор словар€
		);				   
						   
	void DelEntry(		// удалить элемент словар€
		Instance &inst, // экземпл€р словар€
		int id			// идентификатор удал€емого словар€ (уникальный)
		);		

	void UpdEntry(		// изменить элемент словар€
		Instance &inst, // экземпл€р словар€
		int id,			// идентификатор замен€емого словар€
		Entry new_ed	// новый элемент словар€
		);	

	Entry GetEntry(			// получить элемент словар€
		Instance &inst,		// экземпл€р словар€
		int id				// идентификатор получаемого словар€
		);			

	void Print(Instance &d);	// печать словар€
	void Delete(Instance &d);	// удалить словарь
}