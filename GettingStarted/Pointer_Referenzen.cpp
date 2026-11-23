


void test_references_pointer()
{
	// Zeiger (Pointer)

	// Deklaration / Declaration: Speicher für eine Variable reservieren / Vorbelegung
	int n = 999;

	// int s = sizeof(int);

	// Deklaration / Declaration: Speicher für eine Variable reservieren / Vorbelegung
	int* ptr = &n;   // &:  Adresse-von

	// Anweisung / Statement
	n = 123;

	// Mini-Übung: Der Variablen n den Wert 456 zuweisen, ohne den Namen 'n' zu verwenden
	* ptr = 456;       // Indirekter Zugriff lesend / schreiben


	ptr++;   // Dieser Speicher gehört mir erstmal nicht - Debug: Absturz
	
	*ptr = 888;       // Indirekter Zugriff lesend / schreiben
} 