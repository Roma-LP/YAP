#include <iostream>
#include "stdafx.h"
#include "Dictionary.h"

using namespace std;
using namespace Dictionary;


Instance Dictionary::Create(const char name[DICTNAMEMAXSIZE], int size) {
	Instance x;
	if (strlen(name) > DICTNAMEMAXSIZE)	throw THROW01;
	if (size > DICTMAXSIZE)	throw THROW02;

	strcpy_s(x.name, name);
	x.size = 0;
	x.maxsize = size;
	return x;
}

//------------------------------------------

void  Dictionary::AddEntry(Instance &inst, Entry ed) {

	if (inst.size >= inst.maxsize) throw THROW03;

	for (int i = 0; i <= inst.size; i++)
		if (inst.dictionary[i].id == ed.id)	throw THROW04;

	inst.dictionary[inst.size].id = ed.id;
	strcpy_s(inst.dictionary[inst.size].name, ed.name);
	inst.size++;
}

//------------------------------------------

void  Dictionary::DelEntry(Instance &inst, int id) {
	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == id) {
			if (i < inst.size - 1)
				for (int u = i; u <= inst.size - 2; u++) {
					inst.dictionary[u].id = inst.dictionary[u + 1].id;
					inst.dictionary[u].name[0] = 0;
					strcpy_s(inst.dictionary[u].name, inst.dictionary[u + 1].name);
				}
			inst.size--;
			return;
		}

	throw THROW05;
}

//------------------------------------------

Entry   Dictionary::GetEntry(Instance &inst, int id) {
	for (int i = 0; i <= inst.size; i++)
		if (inst.dictionary[i].id == id)
			return inst.dictionary[i];

	throw THROW06;
}

//------------------------------------------

void   Dictionary::UpdEntry(Instance &inst, int id, Entry new_ed) {
	for (int i = 0; i < inst.size; i++)
		if (id != inst.dictionary[i].id && inst.dictionary[i].id == new_ed.id)	throw THROW08;

	for (int i = 0; i <= inst.size; i++)
		if (inst.dictionary[i].id == id) {
			inst.dictionary[i].id = new_ed.id;
			inst.dictionary[i].name[0] = 0;
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			return;
		}

	throw THROW07;
}

//------------------------------------------

void   Dictionary::Delete(Instance &d) {
	for (int i = 0; i <= d.size; i++) {
		d.dictionary[i].name[0] = 0;
		d.dictionary[i].id = NULL;
	}
	d.name[0] = 0;
	d.maxsize = 0;
	d.size = 0;
}

//------------------------------------------

void   Dictionary::Print(Instance &d) {
	cout << "--------- " << d.name << " -----------" << endl;
	for (int i = 0; i < d.size; i++)
		cout << d.dictionary[i].id << " " << d.dictionary[i].name << endl;
	cout << endl;
}