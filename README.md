# Dijkstra2023Herkansing

In dit github zit alles voor een werkende Dijkstra algorithme die werkt op basis van OO en Met behulp van een priority queue.

In dit github zijn een paar bestanden.
node bezit informatie zoals de naam, afstand tot Bron, vector van edges en previues visited node
graph bezit vector van nodes en vector van edges
edge bezit node from, node to en weight van de verbinding
main In dit bestand zit de dijkstra algroitme + alle opstelling voor het werken ervan. Zoals nodes, edges

Het design van dit algorithme :
Er wordt gebruikt gemaakt en OO en priority queue. Ik heb gevonden dat het ik alleen een hpp bestand nodig had voor veel classes omdat er verder niks extra moest. 
Verder hem ik een groot deel van het dijkstra algorithme in de main.cpp folder gezet zodat het goed overzichten lijk is hoe het werkt.

Om het te gebruiken is het simple je vult je nodes in A, B ,C enzo. Daarna vul je jou edges in( dus de vervinding tussen nodes A en B bijv,) daarna push je de edges in de passende node.
Na dat dat gedaan is geeft je de start node en de eind node aan. Eenmaal als dat gedaan is kan je de programma runnen en datn krijg je de kortse pad te zien met de gewicht ervan.

Voor het maken van dit heb ik een paar bronnen gebruikt : https://www.youtube.com/watch?v=pVfj6mxhdMw&t=181s, Stackoverflow, Geeksforgeeks en nog alle powerpoint en code die de HU heeft gegeven.
Bij stackoverflow heb ik meerdere keren een vraag gepost waarmee de community mij heeft geholpen.

OPLETTEN !! Je moet opletten met het gebruik van edges want die zijn 1 richting edges ze gaan maar in 1 richting let hier goed op tijdens het maken.
