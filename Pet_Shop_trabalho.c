#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct PetRegistry{

    char namePet[20];
    float age;
    float weight;
    char petType[20];

} PET;

typedef struct OwnerRegistry{
	
    PET  pet[10];
    char nameOwner[40];
    char contact[11];

} OWNER;

typedef struct ServiceOrder{
	
    int serviceType;
    char veterinary[40];
    char symptoms[100];
    int priority;
    float time;
    int status;
    int bathType;

} SERVICE;

typedef struct VetRegistry {
 
    OWNER client[100];
    SERVICE job[10];
    char crmv[20];
    char vetContact[15];
    int ult;
    int qtd;

} VETERINARY;

typedef struct PaymentRegistry {
	
	OWNER pay[100];
	char cpf[11];
    char adress[100];
    
} PAYMENT;

 // inicializar o serviço e incluir os nomes dos elementos do Veterinario
 // gerar as tds
/* TADs do sistema
    1 - cadastrar o proprietario do pet.
    2 - cadastrar o pet.
    3 - abrir servico.
    4 - status de um servico.
    5 - alterar o veterinario de plantao.
    6 - editar dados.
    7 - excluir dados.
    8 - efetuar o pagamento do servico.
    9 - procurar dados.
    10- fechar sistema.
*/

void ownerRegister(OWNER *owner){
	
    printf("Digite o nome do cliente:\n");
    fgets(owner->nameOwner, 40, stdin);
    getchar();
    printf("Digite o telefone do cliente:\n");
    fgets(owner->contact, 11, stdin);
    getchar();
}
void petRegister(PET *pet){
	
	printf("Digite o nome do pet:\n");
	fgets(pet->namePet, 20, stdin);
	getchar();
	printf("Digite a idade do pet:\n");
	scanf("%f", &pet->age);
	printf("Digite o peso do pet:\n");
	scanf("%f", &pet->weight);
	printf("Digite o tipo de pet:\n");
	fgets(pet->petType, 20, stdin);
	getchar();
	
	
}
void serviceRegister(SERVICE *service){
	
	printf("Digite 1 para consulta ou 2 para banho:\n");
	scanf("%d", &service->serviceType);
	
	switch (service->serviceType){
		case 1:
			printf("Registre o veterinario de plantao: \n");
			fgets(service->veterinary, 40, stdin);
			getchar();
			printf("Registre os sintomas do animal: \n");
			fgets(service->symptoms, 100, stdin);
			getchar();
			printf("Digite 1 para grave, 2 para moderado ou 3 para leve: \n");
			scanf("%d", &service->priority);
			printf("Digite o tempo aproximado de espera em horas: \n");
			scanf("%f", &service->time);
			printf("Digite 1 para atendimento concluido ou 2 para em andamento: \n");
			scanf("%d", &service->status);
		break;
		case 2:
			printf("Digite 1 para banho e tosa ou 2 para apenas banho: \n");
			scanf("%d", &service->bathType);
			printf("Digite o tempo aproximado de espera em horas: \n");
			scanf("%f", &service->time);
			printf("Digite 1 para atendimento concluido ou 2 para em andamento: \n");
			scanf("%d", &service->status);
		break;
		default:
			printf("Digite uma opcao valida!\n");
		break;
	}
}
void serviceStatus(SERVICE *service){
}
void changeVet(SERVICE *service){
}
void editPet(PET *pet){
}
void deletePet(PET *pet){
}
void payService(){
}
void searchData(){
}
void closeSystem(){
}

/*void printData(OWNER *owner){
    printf("Nome do dono: %s\n", owner->nameOwner);
}*/

void menu(){
    printf("----------Seja bem-vindo ao Dino Spoto Pet Shop!----------\n\n");
    printf("Escolha a opcao mais adequada ao seu AUmigo!\n\n");
    printf("Tecle: 1 para cadastrar o proprietario do pet.\n");
    printf("Tecle: 2 para cadastrar o pet.\n");
    printf("Tecle: 3 para abrir servico.\n");
    printf("Tecle: 4 para saber o status de um servico.\n");
    printf("Tecle: 5 para alterar o veterinario de plantao.\n");
    printf("Tecle: 6 para editar dados.\n");
    printf("Tecle: 7 para excluir dados.\n");
    printf("Tecle: 8 para efetuar o pagamento do servico.\n");
    printf("Tecle: 9 para procurar dados de um servico.\n");
    printf("Tecle: 10 para fechar o sistema.\n\n");
}

int main (){

    setlocale(LC_ALL, "Portuguese");
    SERVICE service;
    OWNER owner;
    PET pet;
    
    int operation; 
    do{
        menu();
        scanf("%d", &operation);
        printf("\n");

        switch(operation){
            case 1:
            ownerRegister(OWNER &owner);
            break;
            case 2:
            petRegister(PET &pet);
            break;
            case 3:
            serviceRegister(SERVICE &service);
            break;
            case 4:
            serviceStatus(SERVICE &service);
            break;
            case 5:
            changeVet(SERVICE &service);
            break;
            case 6:
            editPet(PET &pet);
            break;
            case 7:
            deletePet(PET &pet);
            break;
            case 8:
            payService();
            break;
            case 9:
            searchData();
            break;
            case 10:
            closeSystem();
            default:
            printf("Digite uma opcao valida!\n");
            break;
        }
        printf("\n");
    }
    while ((operation) =! 8);

    return 0;
}