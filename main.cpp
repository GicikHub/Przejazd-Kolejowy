
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include <cctype>

using namespace std;

// STAN SYSTEMU
bool szlabanOtwarty = true;
bool alarm = false;
bool pociag = false;
bool samochod = false;
bool przejazdZajety = false;
bool sygnalizacja = false;

// ODLICZANIE
bool odliczanie(int sekundy, string komunikat) {

    cout << "\n" << komunikat << endl;

    for (int i = sekundy; i > 0; i--) {

        cout << "Pozostalo: " << i << " s     \r" << flush;

        for (int j = 0; j < 10; j++) {

            if (_kbhit()) {

                char przycisk = _getch();

                if (przycisk == 27) {
                    cout << "\nOperacja przerwana!\n";
                    return false;
                }
            }

            this_thread::sleep_for(
                chrono::milliseconds(100)
            );
        }
    }

    cout << "Operacja zakonczona!\n";
    return true;
}

// POKAZANIE STANU
void pokazStan() {

    cout << "\n========== STAN PRZEJAZDU ==========\n";

    cout << "Szlaban: "
         << (szlabanOtwarty ? "OTWARTY" : "ZAMKNIETY") << endl;

    cout << "Alarm: "
         << (alarm ? "WLACZONY" : "WYLACZONY") << endl;

    cout << "Pociag: "
         << (pociag ? "WYKRYTY" : "BRAK") << endl;

    cout << "Samochod: "
         << (samochod ? "WYKRYTY" : "BRAK") << endl;

    cout << "Przejazd: "
         << (przejazdZajety ? "ZAJETY" : "WOLNY") << endl;

    cout << "Sygnalizacja: "
         << (sygnalizacja ? "WLACZONA" : "WYLACZONA") << endl;

    cout << "====================================\n";
}

// OTWIERANIE SZLABANU
void otworzSzlaban() {

    if (pociag || przejazdZajety) {
        cout << "\nBLAD! Nie mozna otworzyc szlabanu!\n";
        cout << "Wykryto zagrozenie na przejezdzie!\n";
        return;
    }

    if (odliczanie(5, "Otwieranie szlabanu...")) {
        szlabanOtwarty = true;
        sygnalizacja = false;

        cout << "\nSzlaban zostal otwarty.\n";
    }
}

// ZAMYKANIE SZLABANU
void zamknijSzlaban() {

    if (odliczanie(5, "Zamykanie szlabanu...")) {
        szlabanOtwarty = false;
        sygnalizacja = true;

        cout << "\nSzlaban zostal zamkniety.\n";
    }
}

// WLACZANIE ALARMU
void wlaczAlarm() {

    if (odliczanie(2, "Uruchamianie alarmu...")) {
        alarm = true;
        cout << "\nALARM WLACZONY!\n";
    }
}

// WYLACZANIE ALARMU
void wylaczAlarm() {

    if (pociag || przejazdZajety) {
        cout << "\nUWAGA! Zagrozenie nadal wystepuje!\n";
        return;
    }

    if (odliczanie(2, "Wylaczanie alarmu...")) {
        alarm = false;
        cout << "\nAlarm zostal wylaczony.\n";
    }
}

// WYKRYCIE POCIAGU
void wykryjPociag() {

    if (pociag) {
        cout << "\nPociag jest juz wykryty!\n";
        return;
    }

    // Reakcja bez opoznienia symulacyjnego
    // na wykrycie zagrozenia.
    pociag = true;
    szlabanOtwarty = false;
    sygnalizacja = true;

    cout << "\nWYKRYTO NADJEZDZAJACY POCIAG!\n";
    cout << "Szlaban zostal zamkniety.\n";

    if (przejazdZajety) {
        alarm = true;
        cout << "ALARM! SAMOCHOD NA TORACH!\n";
    }
}

// ODJAZD POCIAGU
void pociagOdjechal() {

    if (!pociag) {
        cout << "\nBrak wykrytego pociagu!\n";
        return;
    }

    if (odliczanie(5, "Oczekiwanie na odjazd pociagu...")) {

        pociag = false;

        cout << "\nPociag opuscil przejazd.\n";

        if (przejazdZajety) {
            alarm = true;
            cout << "ALARM! Przejazd nadal zajety!\n";
        }
        else {
            cout << "Przejazd wolny.\n";
        }
    }
}

// WYKRYCIE SAMOCHODU
void wykryjSamochod() {

    if (samochod) {
        cout << "\nSamochod jest juz wykryty!\n";
        return;
    }

    samochod = true;
    przejazdZajety = true;

    cout << "\nWYKRYTO SAMOCHOD!\n";

    if (pociag) {
        alarm = true;
        cout << "ALARM! SAMOCHOD NA TORACH!\n";
    }
}

// ODJAZD SAMOCHODU
void samochodOdjechal() {

    if (!samochod) {
        cout << "\nBrak samochodu na przejezdzie!\n";
        return;
    }

    if (odliczanie(3, "Oczekiwanie na odjazd samochodu...")) {

        samochod = false;
        przejazdZajety = false;

        cout << "\nSamochod opuscil przejazd.\n";
    }
}

// MENU STEROWANIA
void pokazMenu() {

    cout << "\n";
    cout << "========================================\n";
    cout << "       PANEL STRAZNIKA KOLEJOWEGO\n";
    cout << "========================================\n";

    cout << "[N] Otworz szlaban\n";
    cout << "[K] Zamknij szlaban\n";
    cout << "[L] Wlacz alarm\n";
    cout << "[M] Wylacz alarm\n";
    cout << "[P] Wykryj pociag\n";
    cout << "[O] Pociag odjechal\n";
    cout << "[S] Wykryj samochod\n";
    cout << "[D] Samochod odjechal\n";
    cout << "[W] Wlacz sygnalizacje\n";
    cout << "[E] Wylacz sygnalizacje\n";
    cout << "[A] Sprawdz alarm\n";
    cout << "[C] Sprawdz czujniki\n";
    cout << "[I] Pokaz stan przejazdu\n";
    cout << "[ESC] Wyjscie\n";

    cout << "========================================\n";
    cout << "Nacisnij odpowiedni przycisk...\n";
}

// FUNKCJA GLOWNA
int main() {

    char przycisk;

    while (true) {

        pokazMenu();

        // Odczyt klawisza bez Enter
        przycisk = _getch();

        // Obsluga malych i wielkich liter
        przycisk = toupper(przycisk);

        switch (przycisk) {

        case 'N':
            otworzSzlaban();
            break;

        case 'K':
            zamknijSzlaban();
            break;

        case 'L':
            wlaczAlarm();
            break;

        case 'M':
            wylaczAlarm();
            break;

        case 'P':
            wykryjPociag();
            break;

        case 'O':
            pociagOdjechal();
            break;

        case 'S':
            wykryjSamochod();
            break;

        case 'D':
            samochodOdjechal();
            break;

        case 'W':
            sygnalizacja = true;
            cout << "\nSygnalizacja wlaczona.\n";
            break;

        case 'E':
            if (!pociag && !przejazdZajety) {
                sygnalizacja = false;
                cout << "\nSygnalizacja wylaczona.\n";
            }
            else {
                cout << "\nNie mozna wylaczyc sygnalizacji!\n";
            }
            break;

        case 'A':
            cout << (alarm ?
                "\nALARM AKTYWNY!\n" :
                "\nBrak alarmu.\n");
            break;

        case 'C':
            cout << "\n--- CZUJNIKI ---\n";

            cout << "Pociag: "
                 << (pociag ? "AKTYWNY" : "BRAK") << endl;

            cout << "Samochod: "
                 << (samochod ? "AKTYWNY" : "BRAK") << endl;

            cout << "Przejazd: "
                 << (przejazdZajety ? "ZAJETY" : "WOLNY") << endl;
            break;

        case 'I':
            pokazStan();
            break;

        case 27:
            cout << "\nZamykanie panelu straznika.\n";
            return 0;

        default:
            cout << "\nNieprzypisany przycisk!\n";
        }

        cout << "\nNacisnij dowolny klawisz, aby wrocic do menu...";
        _getch();
    }

    return 0;
}
