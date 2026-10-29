# Laboratory of Experimental Data

Questo repository raccoglie una serie di esercitazioni in C++ dedicate al calcolo numerico, alla simulazione di sistemi fisici e all’analisi dei dati. Il codice è organizzato in modo modulare e sfrutta in modo esplicito i principi della programmazione orientata agli oggetti.

## Obiettivo

L’obiettivo principale del progetto è studiare e implementare metodi numerici per:
- calcolare integrali in modo approssimato;
- confrontare diversi schemi di discretizzazione;
- analizzare l’errore in funzione del passo e del numero di punti;
- risolvere equazioni differenziali;
- modellare sistemi fisici con simulazioni numeriche.

## Approccio orientato agli oggetti

Le librerie presenti nel repository sono progettate in modo da separare chiaramente:
- l’interfaccia matematica;
- la logica di calcolo;
- il comportamento specifico di ciascun modello.

In particolare, il codice utilizza classi astratte e classi derivate per definire comportamenti generici e specializzati. Ad esempio:
- classi base astratte definiscono interfacce come “funzione vettoriale” o “equazione differenziale”;
- classi derivate implementano modelli concreti, come calorimetro ideale, calorimetro reale e integratori numerici;
- il polimorfismo permette di usare lo stesso algoritmo con oggetti diversi, senza duplicare la logica.

Questo rende il codice più riutilizzabile, estendibile e facile da mantenere.

## Contenuto principale

Il repository include:
- librerie per calcolo numerico e manipolazione di vettori;
- implementazioni di metodi di integrazione;
- analisi dell’errore per diversi metodi;
- simulazioni di sistemi termici e dinamici;
- script e file di output per la visualizzazione dei risultati con ROOT.

## Esempi di esercizi inclusi

- studio dell’errore di integrazione con metodi midpoint e midright;
- calcolo dell’integrale tramite metodo Monte Carlo;
- analisi della dipendenza dell’errore dal numero di punti;
- simulazione di un calorimetro ideale e reale;
- risoluzione di equazioni differenziali con Runge-Kutta.

## Tecnologie utilizzate

- C++
- Makefile
- ROOT (per grafici e visualizzazione dei risultati)

## Nota

Il progetto è stato sviluppato come ambiente di laboratorio per esercitazioni di calcolo scientifico, con particolare attenzione alla modularità del codice e alla separazione tra:
- modello matematico;
- algoritmo numerico;
- rappresentazione grafica dei risultati.

Questo rende il repository un buon esempio di utilizzo della programmazione orientata agli oggetti in contesti scientifici e di simulazione numerica.

https://github.com/edoiannu/Laboratory_of_Experimental_Data
