#define MAX_TITKOS 4096
#define OLVASAS_BUFFER 256
#define KULCS_MERET 3
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double atlagos_szohossz (const char *titkos, int titkos_meret);
int tiszta_lehet (const char *titkos, int titkos_meret);
void exor (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret);
int exor_tores (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret);

int main (void) {
	char kulcs[KULCS_MERET];
	char titkos[MAX_TITKOS];
	char *p = titkos;
	int olvasott_bajtok;

	// titkos fajt berantasa
	while ((olvasott_bajtok = read (0, (void *) p, (p - titkos + OLVASAS_BUFFER < MAX_TITKOS) ? OLVASAS_BUFFER : titkos + MAX_TITKOS - p))) {
		p += olvasott_bajtok;
	}

	// maradek hely nullazasa a titkos bufferben
	for (int i = 0; i < MAX_TITKOS - (p - titkos); ++i) {
		titkos[p - titkos + i] = '\0';
	}

	// osszes kulcs eloallitasa
	for (int ii = '0'; ii <= '9'; ++ii)
		for (int ji = '0'; ji <= '9'; ++ji)
			for (int ki = '0'; ki <= '9'; ++ki)
				for (int li = '0'; li <= '9'; ++li)
					for (int mi = '0'; mi <= '9'; ++mi)
						for (int ni = '0'; ni <= '9'; ++ni)
							for (int oi = '0'; oi <= '9'; ++oi)
								for (int pi = '0'; pi <= '9'; ++pi) {
									kulcs[0] = ii;
									kulcs[1] = ji;
									kulcs[2] = ki;
									kulcs[3] = li;
									kulcs[4] = mi;
									kulcs[5] = ni;
									kulcs[6] = oi;
									kulcs[7] = pi;

									if (exor_tores (kulcs, KULCS_MERET, titkos, p - titkos))
									printf("Kulcs: [%c%c%c%c%c%c%c%c]\nTiszta szoveg: [%s]\n",
									 ii, ji, ki, li, mi, ni, oi, pi, titkos);

									// ujra EXOR-ozunk, igy nem kell egy masodik buffer
									exor (kulcs, KULCS_MERET, titkos, p - titkos);
								}

	return 0;
}

double atlagos_szohossz (const char *titkos, int titkos_meret) {
	int sz = 0;
	for (int i = 0; i < titkos_meret; ++i) {
		if (titkos[i] == ' ') {
			++sz;
		}
	}

	return (double) titkos_meret / sz;
}

int tiszta_lehet (const char *titkos, int titkos_meret) {
	// a tiszta szoveg valszeg tartalmazza a gyakori magyar szavakat
	// illetve az átlagos szóhossz vizsgálatával csökkentjük a
	// potenciális töréseket

	double szohossz = atlagos_szohossz (titkos, titkos_meret);

	return szohossz > 6.0 && szohossz < 9.0
	&& strcasestr (titkos, "hogy") && strcasestr (titkos, "nem")
	&& strcasestr (titkos, "az") && strcasestr (titkos, "ha");
}

void exor (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret) {
	int kulcs_index = 0;
	for (int i = 0; i < titkos_meret; ++i) {
		titkos[i] = titkos[i] ^ kulcs[kulcs_index];
		kulcs_index = (kulcs_index + 1) % kulcs_meret;
	}
}

int exor_tores (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret) {
	exor (kulcs, kulcs_meret, titkos, titkos_meret);
	return tiszta_lehet (titkos, titkos_meret);
}
