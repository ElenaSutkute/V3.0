# V3.0

Šiame projekte buvo pridėta galimybė parsisųsti mysetup.exe. Kad tai padaryti reikia turėti parsisiuntus Inno setup. Tai galima atlikti jų oficialiame puslapyje https://jrsoftware.org/isdl.php. Atsidarius Inno setup compiler nukopijuokite į atskirus failus setup.iss ir setup2.iss. setup.iss į "C:/Program files/VU/Vardenis-Pavardenis" sukurs failą "studentai.txt", o setup2.iss sukurs "v1.5.exe" failą tame pačiame aplankale. Kad šie setup failai suveiktų, reikia parsisiųsti v1.5.cpp, sukompiliuoti ir pakeisti kelią iki sukurto v1.5.exe failo jūsų kompiuteryje, taip par reikia parsisiųsti failą studentai.txt ir pakeisti faile setup.iss jo buvimo vietą. 


Naudojimasis kodu:

1. Visų pirma reikia įvesti asmens vardą, tada pavardę, tada vesti norimą kiekį pažymių, norint nutraukti pažymių vedimą, reikia įvesti -1, tada reikia įvesti egzamino pažymį. Šis procesas parodo klasės Zmogus įvesties ir išvesties operatorių perdengimą.

2. Tada programa paklausia, ar norime, kad duomenys būtų saugomi list tipo konteineryje ar vector tipo. Kad pasitinkti tipą, reikia įvesti raidę l, jei norite, kad būtų naudojamas list ir v, jei vector. Tada yra klausiama, ar sugeneruoti failus, atsakius taip bus sugeneruoti 5 tekstiniai failai: 1000, 10 000, 100 000, 1 000 000 ir 10 000 000 srudentų. Tada yra klausiama, ar norime studentus rūšiuoti pagal jų galutinį pažymį (vidurkį) ar pagal pavardes, norint pagal vidurkį, veskite v, pagal pavardes p.  Tuomet yra skaitomi duomenys iš pasirinkto failo. Norint pakeisti failą, iš kurio bus skaitoma, reikia atlikti pakeitimus funkcijoje StudentuSkirstymas. Kai duomenys yra nuskaityti, studentai yra surūšiuojami pagal pradžioje pasirinktą būdą, paskaičiuojamas studentų galutinis pažymys pagal vidurkį ir studentai yra suskirtomi į du failus: Moksliukai, kurių vidurkis yra >=5 ir Vargšiukai, kurių vidurkis <5. Eigoje yra skaičiuojami visų šių operacijų įvykdymo laikai.

   
3. tada paklausiama ar norite nuskaityti duomenis iš failo. Galimi atsakymai yra tik taip arba ne.
   
     3.1. Įvedus taip, duomenys yra nuskaitomi iš failo kursiokai.txt. Jei vedant pažymius į tekstinį failą buvo padarytos klaidos,   studento nebus galutiniame sąraše ir bus parašyta kelintas studentas turi klaidų savo pažymių tarpe.
   
     3.2. Įvedus ne, reikia pasirinkti kiek norėsite vesti studentų. Galima vesti tik skaičius.
   
     3.2.1. Tuomet reikia įvesti studento vardą bei pavardę.
   
     3.2.2. Klausiama ar norite įvesti studento pažymius bei egzamino rezutatą ranka, ar kad kompiuteris juos sugeneruotų automatiškai. Galimi įvedimo rezultatai taip arba ne.
   
     3.2.2.1. Įvedus taip galite vesti kiek norite studento pažymių, norėdami nutraukti įvedimą parašykite -1; Tuomet reikia įvesti egzamino rezultatą. Rezultatai būtinai turi būtų (0,10] ribose.
   
     3.2.2.2. Įvedus ne reikia pasirinkti kiek buvo atliktų namų darbų ir tada studento namų darbų ir egzamino rezultatai bus generuojami automatiškai.
Galutiniame rezultate matysime studentų pavades ir vardus surūšiuotus abeceliškai ir jų galutinį dalyko rezutatą, paskaičiuotą tiek pagal medianą, tiek pagal vidurkį.
