# lab3pt2

Nome: Davi Micale - TIA: 32096062

Nome: Victor Rodrigues - TIA: 32273134

Nome: Yuri - TIA: 32230877

Turma: 4N

**Relatório de evidências**

Neste relatório vamos demonstrar a construção de dois códigos para representar o cálculo pi. Ambos utulizam threads, porém um deles trabalha com o uso de um mutex. Apresentaremos o passo a passo e as diferençãs entre eles a seguir.

1 - Criamos um repositório no GitHub e fizemos as parametrizações para que esse repositório se ligasse na nossa máquina AWS.

![so_1](https://github.com/davimicale/lab3pt2/assets/62074503/dbfc8be4-6c10-4438-8a2c-343bcba40cad)

2- Criamos um arquivo dentro do repositório e atualizamos o código de cálculo de pi disponibilidzado pelo professor, este utiliza Pthreads.
![so_2](https://github.com/davimicale/lab3pt2/assets/62074503/013e6c7f-f32b-402c-8cc9-22aeaed7b017)
![so_3](https://github.com/davimicale/lab3pt2/assets/62074503/615d7797-1382-45d8-a50a-bbf9dc12c5ab)

3- Logo em seguida, o compilamos e realizamos alguns testes. Em ambos os testes optamos por realizar 10 iterações, no primeiro utilizamos apenas uma thread e no segundo 5 threads. Dessa forma, podemos representar a vantagem da utilização de threads. A principal é que em um código que não utiliza threads, todo o cálculo é executado de forma sequencial em uma única thread. Isso significa que cada termo da série de Leibniz é calculado em ordem, um após o outro. Já um código que utiliza threads, o trabalho é dividido entre múltiplas threads, permitindo que várias partes da série de Leibniz sejam calculadas simultaneamente. Cada thread lida com uma parte do cálculo.
![so_4](https://github.com/davimicale/lab3pt2/assets/62074503/5ce8b0cd-8af9-4f8b-b4cf-6dc2d259da45)
![so_5](https://github.com/davimicale/lab3pt2/assets/62074503/e33b1bee-43c6-4ba6-a422-b24139e8fdbf)

Entretanto, o uso de várias threads pode resultar em concorrência. A concorrência ocorre quando múltiplas threads estão tentando acessar, modificar ou atualizar recursos compartilhados simultaneamente.
![so_6](https://github.com/davimicale/lab3pt2/assets/62074503/4bab0aea-a61b-41a3-b040-a15830100d90)
![so_7](https://github.com/davimicale/lab3pt2/assets/62074503/75176ff6-244a-4b2a-9479-6bca87315a29)
![so_8](https://github.com/davimicale/lab3pt2/assets/62074503/5152b5ff-f08b-41a5-9296-b5635256dfc2)
![so_9](https://github.com/davimicale/lab3pt2/assets/62074503/a766ea05-5bc4-421c-98e8-49b5f6208d8d)
![so_10](https://github.com/davimicale/lab3pt2/assets/62074503/f0845524-b37e-434b-9367-2b1732d3ad0c)
![so_11](https://github.com/davimicale/lab3pt2/assets/62074503/d070f866-20e9-47a0-a21b-2213c7cadeac)
![so_12](https://github.com/davimicale/lab3pt2/assets/62074503/3f8800c2-ff32-4f03-85f0-04256431b5e8)
![so_13](https://github.com/davimicale/lab3pt2/assets/62074503/be9c4860-fbe3-4802-a165-6ad85a7fbee3)
