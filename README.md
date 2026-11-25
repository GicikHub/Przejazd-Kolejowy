
# 🚦 Railway Crossing Control System

\<p align="center"\> \*\*Symulator automatycznego przejazdu kolejowo-drogowego\*\*

System sterowania szlabanem, sygnalizacją świetlną i alarmem z wykorzystaniem języka C++.

\</p\>

---

## 📌 O projekcie

Projekt przedstawia symulator systemu kontroli przejazdu kolejowo-drogowego, umożliwiający sterowanie szlabanem, alarmem oraz sygnalizacją, a także symulowanie wykrywania nadjeżdżającego pociągu i samochodu.

Program działa w konsoli i wykorzystuje interaktywny panel sterowania, obsługiwany za pomocą klawiatury.

Głównym celem projektu jest odwzorowanie podstawowych mechanizmów działania przejazdu kolejowego oraz zaprezentowanie logiki reagowania na potencjalne sytuacje niebezpieczne.

## ✨ Funkcjonalności

- 🚧 **Sterowanie szlabanem** – otwieranie i zamykanie z symulowanym czasem operacji.
- 🚨 **System alarmowy** – możliwość ręcznego uruchamiania i wyłączania alarmu.
- 🚆 **Detekcja pociągu** – symulacja wykrycia nadjeżdżającego pociągu.
- 🚗 **Detekcja samochodu** – symulacja wykrycia pojazdu na przejeździe.
- 💡 **Sygnalizacja ostrzegawcza** – ręczne sterowanie sygnalizacją.
- ⏱️ **Odliczanie czasu** – wizualizacja czasu wykonywania operacji.
- 🛑 **Przerywanie operacji** – możliwość anulowania odliczania klawiszem ESC.
- 📊 **Monitorowanie stanu** – podgląd aktualnego stanu wszystkich elementów systemu.
- 🔒 **Kontrola bezpieczeństwa** – blokowanie wybranych operacji w przypadku wykrycia zagrożenia.

## 🎮 Sterowanie

Program obsługiwany jest za pomocą klawiatury. Nie trzeba naciskać ENTER po wybraniu odpowiedniego przycisku.

| Klawisz | Funkcja |
| --- | --- |
| `N` | Otwórz szlaban |
| `K` | Zamknij szlaban |
| `L` | Włącz alarm |
| `M` | Wyłącz alarm |
| `P` | Wykryj pociąg |
| `O` | Symuluj odjazd pociągu |
| `S` | Wykryj samochód |
| `D` | Symuluj odjazd samochodu |
| `W` | Włącz sygnalizację |
| `E` | Wyłącz sygnalizację |
| `A` | Sprawdź stan alarmu |
| `C` | Sprawdź czujniki |
| `I` | Wyświetl stan przejazdu |
| `ESC` | Zamknij program |

## 🧠 Logika działania systemu

Program wykorzystuje zestaw zmiennych logicznych (`bool`) do przechowywania aktualnego stanu przejazdu.

Najważniejsze zmienne:

| Zmienna | Opis |
| --- | --- |
| `szlabanOtwarty` | Informacja o stanie szlabanu |
| `alarm` | Informacja o aktywności alarmu |
| `pociag` | Informacja o wykryciu pociągu |
| `samochod` | Informacja o wykryciu samochodu |
| `przejazdZajety` | Informacja o zajętości przejazdu |
| `sygnalizacja` | Informacja o stanie sygnalizacji |

### ⚠️ Przykładowe sytuacje bezpieczeństwa

**1\. Wykrycie nadjeżdżającego pociągu**

- System automatycznie zamyka szlaban.
- Włącza sygnalizację ostrzegawczą.
- Jeżeli na przejeździe znajduje się samochód, aktywuje alarm.

**2\. Próba otwarcia szlabanu podczas zagrożenia**

- System sprawdza, czy wykryto pociąg.
- Sprawdza, czy przejazd jest zajęty.
- Jeżeli występuje zagrożenie, blokuje otwarcie szlabanu.

**3\. Wykrycie samochodu na przejeździe**

- System oznacza przejazd jako zajęty.
- Jeżeli w tym samym czasie wykryty jest pociąg, uruchamia alarm.

**4\. Odjazd pociągu**

- Program symuluje oczekiwanie na odjazd.
- Aktualizuje stan pociągu.
- Sprawdza, czy przejazd jest wolny.
- Jeżeli samochód nadal znajduje się na przejeździe, alarm pozostaje aktywny.

## ⏱️ Czasy wykonywania operacji

| Operacja | Czas |
| --- | --- |
| Otwieranie szlabanu | 5 sekund |
| Zamykanie szlabanu | 5 sekund |
| Włączanie alarmu | 2 sekundy |
| Wyłączanie alarmu | 2 sekundy |
| Odjazd pociągu | 5 sekund |
| Odjazd samochodu | 3 sekundy |

Operacje czasowe realizowane są z wykorzystaniem biblioteki `chrono` oraz `thread`.

## 🛠️ Technologie

Projekt został napisany w języku:

- **C++** – główny język programowania.
- **iostream** – obsługa wejścia i wyjścia.
- **string** – obsługa tekstu.
- **thread** – obsługa opóźnień.
- **chrono** – zarządzanie czasem.
- **conio.h** – odczyt klawiszy bez konieczności naciskania ENTER.
- **cctype** – konwersja małych liter na wielkie.

## 💻 Uruchomienie projektu

### Wymagania

- System operacyjny Windows.
- Kompilator obsługujący C++11 lub nowszy.
- Środowisko programistyczne, np. Visual Studio lub Code::Blocks.

### Kompilacja

Jeżeli korzystasz z kompilatora g++, wykonaj polecenie:

bash

```bash
g++ main.cpp -o railway_crossing -std=c++11
```

### Uruchomienie

bash

```bash
./railway_crossing
```

W systemie Windows:

bash

```bash
railway_crossing.exe
```

## 📂 Struktura projektu

text

```text
Railway-Crossing-Control-System/
│
├── main.cpp
└── README.md
```

## 🎯 Cel projektu

Projekt ma charakter edukacyjny i został stworzony w celu praktycznego wykorzystania podstaw programowania w języku C++.

Pozwala przećwiczyć:

- instrukcje warunkowe (`if`, `else`, `switch`),
- funkcje i podział programu na moduły,
- zmienne logiczne (`bool`),
- pętle (`while`, `for`),
- obsługę klawiatury,
- biblioteki standardowe C++,
- symulowanie działania systemów sterowania,
- projektowanie logiki reagowania na sytuacje awaryjne.

## ⚠️ Ważna informacja

Jest to symulacja edukacyjna działająca w konsoli. Program nie jest certyfikowanym systemem sterowania ruchem kolejowym i nie powinien być wykorzystywany do sterowania rzeczywistą infrastrukturą kolejową.

---

\<p align="center"\> \*\*🚦 Railway Crossing Control System\*\*

_Created with ❤️ using C++_

\</p\>
