# Konvexní obal množiny bodů v rovině (convex hull)
## Popis zadání
_Konvexní obal (convex hull) množiny bodů si lze jednoduše představit jako nejmenší konvexní mnohoúhelník, uvnitř 
kterého leží všechny body množiny. Jako konkrétní algoritmus je možné zvolit třeba Quickhull. Vstupem pro aplikaci bude 
textový soubor se souřadnicemi bodů, výstupem pak bude seznam vrcholů konvexního obalu. Doporučujeme si napsat 
jednoduchý generátor vstupních dat a program či skript pro převod vstupních a výstupních dat do obrázku SVG pro snadnou 
vizualizaci a ověření správnosti řešení._

## Popis mé implementace
Implementace využívá pouze jedno vlákno. Na výpočet konvexního obalu jsem implementoval (rekurzivní) algoritmus 
Quickhull. Program podporuje zpracování více souborů jako argumenty najednou a naopak pokud neposkytneme žádný argument,
program si vygeneruje vlastní vstup a informuje uživatele. Vstupní a výstupní fily jsou realizované jako dvojice floatů 
(bod) na jednom řádku (příklad v example_data). Program dokáže vygenerovat vstupní file bez jeho zprocesování pomocí 
přepínače --generate-input, více info v usage (-h). Repozitář také obsahuje skript visualize_points.py 
(vyžaduje matplotlib), kterým můžeme vizualizovat input a output fily a zkontrolovat tak výsledek.