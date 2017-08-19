#include <iostream>
#include <fstream>
#include <cmath>
#include <locale.h>
#include <stdlib.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
	int Vmax=0, Vmin=0, operacao=0;
	int b, t;
	float fi=0;
	float pi=3.1415926535;
    int N=0;
    float nivel[N];
    float amostragem[N];
    float xq[N];
    float xe[N];
    char novamente;
    do{
        cout<<"\n----------------------------------------------------------------";
        cout<<"\n----------------------------------------------------------------";
        cout<<"\n      C�lculo de valores de amostragem e quantiza��o!           ";
        cout<<"\n----------------------------------------------------------------";
        cout<<"\n----------------------------------------------------------------";
        double frequencia=0, deltaq=0;//essas variaveis precisam ser criadas aqui, pois caso fora do la�o do while, ela acumular� a cada vez que o usario entrar no la�o
        float x=1, q=0, amplitude=0;
        //Solicitando os dados necess�rios para o c�lculo
        cout <<"\nDigite o valor de b para defini��o do n�mero de intervalos: ";
        cin>>b;
        N = pow(2,b);
        cout<<"\nO n�mero de intervalos �: " << N <<"\n\n";
        cout<<"\n Qual tipo de fun��o deseja calcular: ";
        cout<< "\n\n Op��o 1: Asen(Wot+fase)\n";
        cout<< "\n Op��o 2: Acos(Wot+fase)\n";
        cout<< "\n Op��o 3: Asen(Wot+fase)+ Bcos(Wot+fase)\n";
        cout <<"\n\nDigite o n�mero da sua op��o ";
        cin>>operacao;

        ofstream gravar;
        gravar.open("pds.txt");
        gravar<<"\n-------------------Tabela--------------------";
        gravar<<"\n---------------------------------------------\n";
        gravar<<"#Coluna 1: Amostras";
        gravar<<"\n#Coluna 2: N�vel de Quantiza��o";
        gravar<<"\n#Coluna 3: Amostragem ";
        gravar<<"\n#Coluna 4: Quantiza��o ";
        gravar<<"\n#Coluna 5: Erro de Quantiza��o ";
        gravar<<"\n--------------------------------------------";
        gravar<<"\n--------------------------------------------\n";
        switch(operacao){
                    case 1:
                        cout<<"\nDigite o valor da amplitude: ";
                        cin>>amplitude;
                        cout<<"\nDigite o valor m�ximo de pico: ";
                        cin>>Vmax;
                        cout<<"\nDigite o valor m�nimo de pico: ";
                        cin>>Vmin;
                        cout<<"\nDigite o valor da frequ�ncia(Wo) da fun��o: ";
                        cin>>frequencia;
                        cout<<"\nDigite o valor da fase: ";
                        cin>>fi;
                        deltaq = (Vmax - (Vmin))/(double)N;
                        cout <<"\nO intervalo de quantiza��o �: " << deltaq << "\n";
                        cout<<"\n-------------------Tabela--------------------";
                        cout<<"\n-------------------------------------------\n";
                        cout<<"#Coluna 1: Amostras";
                        cout<<"\n#Coluna 2: N�vel de Quantiza��o";
                        cout<<"\n#Coluna 3: Amostragem ";
                        cout<<"\n#Coluna 4: Quantiza��o ";
                        cout<<"\n#Coluna 5: Erro de Quantiza��o ";
                        cout<<"\n-------------------------------------------\n";
                        cout<<"\n-------------------------------------------\n";
                        //O Intervalo e o N�vel de quantiza��o
                        for(t=0; t<N; t++){
                            q=x;
                            x=(x-deltaq); //intervalo de q
                            nivel[t] = (q+(x))/2; //media dos intervalos
                            amostragem[t]= roundf(amplitude*sin((2*pi*frequencia*t)+fi)*10000)/10000;
                            for(int e= (N-1); e >= 0; e--){
                                    if(nivel[e-1] < amostragem[t] and (amostragem[t] < nivel[t])){
                                        xq[t]=round(amostragem[e]*100)/100;
                                    }
                            }
                        xe[t] = (amostragem[t] - (xq[t]));
                        cout << "\n " << t << "\t\t" << nivel[t] << "\t\t" << amostragem[t] << "\t\t" << xq[t] << "\t\t" << xe[t]<<"\n ";
                        gravar<< "\n " << t << "\t\t" << nivel[t] << "\t\t" << amostragem[t] << "\t\t" << xq[t] << "\t\t" << xe[t]<<"\n ";
                        }

                    break;
                    case 2:
                            cout<<"\nDigite o valor da amplitude: ";
                        cin>>amplitude;
                        cout<<"\nDigite o valor m�ximo de pico: ";
                        cin>>Vmax;
                        cout<<"\nDigite o valor m�nimo de pico: ";
                        cin>>Vmin;
                        cout<<"\nDigite o valor da frequ�ncia(Wo) da fun��o: ";
                        cin>>frequencia;
                        cout<<"\nDigite o valor da fase: ";
                        cin>>fi;
                        deltaq = (Vmax - (Vmin))/(double)N;
                        cout <<"\nO intervalo de quantiza��o �: " << deltaq << "\n";
                        cout<<"\n-------------------Tabela--------------------";
                        cout<<"\n-------------------------------------------\n";
                        cout<<"#Coluna 1: Amostras";
                        cout<<"\n#Coluna 2: N�vel de Quantiza��o";
                        cout<<"\n#Coluna 3: Amostragem ";
                        cout<<"\n#Coluna 4: Quantiza��o ";
                        cout<<"\n#Coluna 5: Erro de Quantiza��o ";
                        cout<<"\n-------------------------------------------\n";
                        cout<<"\n-------------------------------------------\n";
                        //O Intervalo e o N�vel de quantiza��o
                        for(t=0; t<N; t++){
                            q=x;
                            x=(x-deltaq); //intervalo de q
                            nivel[t] = (q+(x))/2; //media dos intervalos
                            amostragem[t]= roundf(amplitude*cos((2*pi*frequencia*t)+fi)*10000)/10000;
                            for(int e= (N-1); e >= 0; e--){
                                    if(nivel[e-1] < amostragem[t] and (amostragem[t] < nivel[t])){
                                        xq[t]=round(amostragem[e]*100)/100;
                                    }
                            }
                        xe[t] = (amostragem[t] - (xq[t]));
                        cout << "\n " << t << "\t\t" << nivel[t] << "\t\t" << amostragem[t] << "\t\t" << xq[t] << "\t\t" << xe[t]<<"\n ";
                        gravar<< "\n " << t << "\t\t" << nivel[t] << "\t\t" << amostragem[t] << "\t\t" << xq[t] << "\t\t" << xe[t]<<"\n ";
                        }


                    break;
                    case 3:
                        float amplitudeseno=0, amplitudecosseno=0, freqseno=0, freqcosseno=0, ficos=0;
                        cout<<"\nDigite o valor da amplitude do seno: ";
                        cin>>amplitudeseno;
                        cout<<"\nDigite o valor da amplitude de cosseno: ";
                        cin>>amplitudecosseno;
                         cout<<"\nDigite o valor da frequ�ncia do seno: ";
                        cin>>freqseno;
                        cout<<"\nDigite o valor da frequ�ncia de cosseno: ";
                        cin>>freqcosseno;
                        cout<<"\nDigite o valor m�ximo de pico: ";
                        cin>>Vmax;
                        cout<<"\nDigite o valor m�nimo de pico: ";
                        cin>>Vmin;
                        cout<<"\nDigite o valor da fase de seno: ";
                        cin>>fi;
                        cout<<"\nDigite o valor da fase de cosseno: ";
                        cin>>ficos;
                        deltaq = (Vmax - (Vmin))/(double)N;
                        cout <<"\nO intervalo de quantiza��o �: " << deltaq << "\n";
                        cout<<"\n-------------------Tabela--------------------";
                        cout<<"\n-------------------------------------------\n";
                        cout<<"#Coluna 1: Amostras";
                        cout<<"\n#Coluna 2: N�vel de Quantiza��o";
                        cout<<"\n#Coluna 3: Amostragem ";
                        cout<<"\n#Coluna 4: Quantiza��o ";
                        cout<<"\n#Coluna 5: Erro de Quantiza��o ";
                        cout<<"\n-------------------------------------------\n";
                        cout<<"\n-------------------------------------------\n";
                        //O Intervalo e o N�vel de quantiza��o
                        for(t=0; t<N; t++){
                            q=x;
                            x=(x-deltaq); //intervalo de q
                            nivel[t] = (q+(x))/2; //media dos intervalos
                            amostragem[t]= roundf((amplitudeseno*sin((2*pi*freqseno*t)+fi)+amplitudecosseno*cos((2*pi*freqcosseno*t)+ficos))*10000)/10000;
                            for(int e= (N-1); e >= 0; e--){
                                    if(nivel[e-1] < amostragem[t] and (amostragem[t] < nivel[t])){
                                        xq[t]=round(amostragem[e]*100)/100;
                                    }
                            }
                        xe[t] = (amostragem[t] - (xq[t]));
                        cout << "\n " << t << "\t\t" << nivel[t] << "\t\t" << amostragem[t] << "\t\t" << xq[t] << "\t\t" << xe[t]<<"\n ";
                        gravar<< "\n " << t << "\t\t" << nivel[t] << "\t\t" << amostragem[t] << "\t\t" << xq[t] << "\t\t" << xe[t]<<"\n ";
                        }
                    break;
                    gravar.close();
            cout<<"\n------------------------------------------\n";
            cout<<"\n------------------------------------------\n";
        }
            cout<<"\nDeseja calcular novamente? (s|n) ";
            cin>>novamente;
            cout<<"\n\n";
            system("cls");
    }while(novamente == 's');
    system ("pause");
    return 0;
}
