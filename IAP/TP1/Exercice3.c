#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, delta;
    float roots[] = {0.0, 0.0}; // Dans R, P(X) peut avoir 0, 1 ou 2 racines.
    // scan des coefficients
    printf("Veuillez entrer les coefficients du polynôme:\n");
    printf("\na:");
    scanf("%d", &a);
    printf("\nb:");
    scanf("%d", &b);
    printf("\nc:");
    scanf("%d", &c);

    // calcul du discriminant
    delta = b * b - 4 * a * c;

    // calcul des racines
    if (delta < 0) {
        printf("Le polynôme n'a pas de racines réelles\n");
    } else if (delta == 0) {
        roots[0] = (float)-b / (2 * a); // (float) force la division par au moins un réel, pour obtenir le bon résultat
        printf("Le polynôme a une racine double x1 = x2 = %1.3f\n", roots[0]); // %1.3f arrondit à 3 chiffres après la virgule
    } else {
        roots[0] = ((float)-b - sqrt(delta)) / (2 * a);
        roots[1] = ((float)-b + sqrt(delta)) / (2 * a);
        printf("Les racines du polynôme sont:\nx1=%1.3f\nx2=%1.3f\n", roots[0], roots[1]);
    }
    return 0;
}
