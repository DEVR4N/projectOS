#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;
void firstCome_firstServe(struct node* header);
void select_menu(struct node* header);

struct node {
int p_time,burst_time,arrival_time,pyyy_;
struct node *next;
};

int if_node_empty(struct node * header);
//node structssssss
struct node * comp_control(struct node * header, int count);
struct node * f_insert(struct node * header, int p_time, int burst_t, int arrival_t, int pyn);
struct node * f_clear(struct node * header);
struct node * node_crt(int p_time, int burst_t, int arrival_t, int pyn);

int main()
{
	struct node *header = NULL;
	int p_time,burst_t,arrival_t,pyn;
	ifstream file_in;
	bool loop = true;
	file_in.open("input.txt");
	//bu burda kalsin \nPlease enter from the options !\n"

	if (file_in.is_open()) {

		while (file_in >> p_time >> burst_t >> arrival_t >> pyn) 
		{
			header = f_insert(header, p_time, burst_t, arrival_t, pyn);
		}
	}
	file_in.close();
	while (loop) {
		int select_option;
		cout << endl << "\t21704967 Devran Demir\n";
		cout << endl << ">> 1 << CPU Scheduling Method\n";
		cout << endl << ">> 0 << Finish Program";
		cout << endl << "Choose one of the options ->>";
		cin >> select_option;

		if (select_option == 1) {
			select_menu(header);
		}
		else if (select_option == 0)
		{
			return 0;
		}
		else 
			cout <<"\nPlease enter from the options !\n";
	}
	cin.ignore();
	return 0;
}

void select_menu(struct node* header) {
	bool loop = true;
	int select_option;
	char menu;
	while (loop) 
	{
		cout<< endl << "\n>> 1 << First Come, First Serve Scheduling";
		cout<< endl << "Choose one of the options ->>";
		cin >> select_option;
		if (select_option == 1) 
		{
			firstCome_firstServe(header);
			cout <<"\nProcess completed ! Pls check Output.txt !";
			loop = false;
		}	
		else 
			cout << "\nPlease enter from the options !\n";				
	}
	cin >> menu;
}

void firstCome_firstServe(struct node* header) {
	//first come first serve function
	float waittime = 0;
	float average = 0;
	int prooo;
	struct node *temp = header;
	ofstream file_add("Output.txt");
	file_add <<">> FCFS METHOD <<\n";
	file_add<<"p wait time ; \n";
	while (!(if_node_empty(temp))) {
		file_add << "P" << prooo << ": " << waittime << endl;
		average += waittime;
		waittime += (int)temp->burst_time - '0';
		temp = f_clear(temp);
		prooo++;} /* out of avg -->>>> */ file_add << "AVG WAIT TIME -->> " << average / (prooo - 1);
}

    int if_node_empty(struct node* header)
	{
	if (header == NULL) {
		return 1;
	}
	else 
		return 0;	}

struct node* f_insert(struct node* header, int p_time, int burst_t, int arrival_t, int pyn) {
	struct node* temp = node_crt(p_time, burst_t, arrival_t, pyn);
	struct node* headerTemp;
	if (header == NULL) {
		header = temp;
		return header;
	}
	headerTemp = header;
	while (headerTemp->next != NULL)
	headerTemp = headerTemp->next;
	headerTemp->next = temp;
	return header;
}

struct node* f_clear(struct node* header) {
	struct node* temp;
	
	if (header == NULL)
	return header;

	temp = header;
	header = header->next;
	free(temp);

	return header;
}
struct node* node_crt(int p_time, int burst_t, int arrival_t, int pyn) {
	struct node *header = NULL;
	header = (struct node *) malloc(sizeof(node));
	header->p_time = p_time;
	header->burst_time = burst_t;
	header->arrival_time = arrival_t;
	header->pyyy_ = pyn; header->next = NULL;	
	return header;
}
