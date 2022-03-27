# Programozás alapjai 2 házi feladat

## Specifikáció

A program egy nyilvántartást valósít meg egy egyesület csapatairól. Minden csapatnak van egy 
neve, alaplétszáma és egy edzője, illetve vannak meccsei is, amikről tudni az ellenfél csapat nevét, 
a meccs időpontját és a helyszínét. A sportegyesület 3 féle sportággal foglalkozik: labdarúgás, 
kosárlabda és kézilabda. A focicsapatnak két edzője van; a kosárlabdacsapatnak van egy pom-pom csapata, aminek nyilvántartják a létszámát; a kézilabda csapat meg évente kap támogatást,
aminek az összege el van tárolva.

A programot indítva egy menü nyílik meg ahonnan lehetőség van a csapatok listázására, új csapat 
hozzáadására, csapat törlésére, csapatra keresésre és a programból való kilépésre.
* Ha listázzuk a csapatokat, akkor soronként kiírja a csapatok nevét, fajtáját (foci, kosár, 
kézi), alaplétszámát, edzőjének a nevét (foci csapatnál mindkét edző nevét), 
kosárcsapatnál a pom-pom lányok számát, kézilabdacsapatnál a támogatás összegét.
Minden csapathoz tartozik egy sorszám is, aminek a beírásával lehet kilistázni a 
meccseinek az adatait soronként sorszámmal ellátva. Itt lehet törölni meccset vagy 
hozzáadni új meccset. Törlés menüpontnál a meccs sorszámát kell megadni. Meccs 
hozzáadása menüpontban a program bekéri az ellenfél nevét, a meccs időpontját és 
helyszínét.
* Új csapat hozzáadása menüpontban először ki kell választani, hogy milyen típusú csapatot 
kívánunk létrehozni (foci, kosár, kézi), ezek után a program bekéri a csapat nevét(nem 
lehet benne ’,’, alaplétszámát, edzőjének a nevét, foci esetén a másik edző nevét, kosárnál 
a pom-pom csapat létszámát, kézicsapatnál a támogatás összegét.
* Ha a csapat törlése menüpontot válasszuk, akkor a program bekéri a törölni kívánt csapat 
pontos nevét, kilistázza azokat a csapatokat, amelyeknek ez a neve, ha több csapatnál is 
talál egyezést, akkor ki kell választani, hogy melyiket kívánjuk törölni.
* A keresés menüpontban egy csapat nevére lehet keresni, ha több egyezés is van akkor az 
összes találat kilistázódik.
* A kilépés menüpontot választva a megtörténik a mentés és kilép a program.
