//Pawel Jandula
#include <stdio.h>
#include <stdlib.h>

int compare (const char* operation, const char* compare) {
    if ((*operation == *compare) && (*(operation + 1) == *(compare + 1)) && (*(operation + 2) == *(compare + 2))) {
        return 1;
    }
    return 0;
}
void addFrontRow (int*** cture, int* rows, int** ColInRows, int howManyElements) {// dodaje pusty wiersz
    int* newRow = (int*)malloc(howManyElements * sizeof(int));
    int** newcture = (int**)malloc( (*rows + 1) * sizeof(int*));
    *newcture = newRow;
    int i;
    for(i = 0; i < *rows; i ++){
        *(newcture + i + 1) = *(*(cture) + i);
    }
    free(*cture);
    *cture = newcture;// tutaj czy na koncu?
    int* newCols = (int*)malloc((*rows + 1) * sizeof(int));
    *(newCols) = howManyElements;
    for( i = 0; i < *rows; i++){
        *(newCols + i + 1) = *(*ColInRows + i);
    }
    free(*ColInRows);
    *ColInRows = newCols;
    *rows += 1;
}

void addLastRow (int*** cture, int* rows, int** ColInRows, int howManyElements) {

    if (howManyElements <= 0) return;
    int* newRow = (int*)malloc(howManyElements * sizeof(int));
    int** newcture = (int**)malloc( (*rows + 1) * sizeof(int*));
    int i;
    for(i = 0; i < *rows; i++){
        *(newcture + i) = *(*(cture) + i);
    }
    *(newcture + *rows) = newRow;
    free(*cture);
    *cture = newcture;
    int* newCols = (int*)malloc((*rows + 1) * sizeof(int));
    for(i = 0; i < *rows; i++){
        *(newCols + i) = *((*ColInRows) + i);
    }
    *(newCols + *rows) = howManyElements;
    free(*ColInRows);
    *ColInRows = newCols;
    *rows += 1;
}

void addFirstColumn (int*** cture, int* rows, int** ColInRows, int howMuch) {
    if (howMuch <= 0) return;
    int ilerows = (howMuch > *rows) ? *rows : howMuch;
    int i;
    for (i = 0; i < ilerows; i++) {
        int newSize = (*((*ColInRows) + i)) + 1;
        int* newRow = (int*)malloc(newSize * sizeof(int));
        int j;
        for (j = 0; j < (*((*ColInRows) + i)); j++) {
            *(newRow + j + 1) = *(*(*cture + i) + j);
        }
        free(*(*cture + i));
        *(*cture + i) = newRow;
        *(*ColInRows + i) = newSize;
    }
}

void addLastColumn (int*** cture, int* rows, int** ColInRows, int howMuch) {
    if (howMuch <= 0) return;
    int ilerows = (howMuch > *rows) ? *rows : howMuch;
    int i;
    for (i = 0; i < ilerows; i++) {
        int newSize = (*((*ColInRows) + i)) + 1;
        int* newRow = (int*)malloc(newSize * sizeof(int));
        int j;
        for (j = 0; j < (*((*ColInRows) + i)); j++) {
            *(newRow + j) = *(*(*cture + i) + j);
        }
        free(*(*cture + i));
        *(*cture + i) = newRow;
        *(*ColInRows + i) = newSize;
    }
}
void alr(int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements) {
    addLastRow(cture,rows, ColInRows, howManyElements);
    int i;
    if(howManyElements> 0) {
        for (i = 0; i < howManyElements; i++) {
            *(*(*(cture) + *rows - 1) + i) = *(elements + i);
        }
    }
}
void insertBeforeRow (int*** cture, int* rows, int** ColInRows, int howManyElements, int rowNumber) {
    if(rowNumber >= *rows) {
        alr(cture, rows, ColInRows, NULL, howManyElements);
        return;
    }

    int* newCals = (int*)malloc((*rows + 1) * sizeof(int));
    int** newcture = (int**)malloc((*rows + 1) * sizeof(int*));

    int i;
    for(i = 0; i < rowNumber; i++){
        *(newcture + i) = *((*cture) + i);
        *(newCals + i) = *((*(ColInRows)) + i);
    }
    *(newcture + rowNumber) = (int*)malloc(howManyElements * sizeof(int));
    *(newCals + rowNumber) = howManyElements;

    for(i = rowNumber + 1; i < *rows + 1; i++){
        *(newcture + i) = *((*cture) + i - 1);
        *(newCals + i) = *((*ColInRows) + i - 1);
    }
    free(*cture);
    *cture = newcture;
    free(*ColInRows);
    *ColInRows = newCals;
    *rows += 1;
}

void insertAfterRow (int*** cture, int* rows, int** ColInRows, int howManyElements, int rowNumber) {
    int* newCals = (int*)malloc(howManyElements * sizeof(int));
    int** newcture = (int**)malloc( (*rows + 1) * sizeof(int*));
    int i;
    for(i = 0; i <= rowNumber; i ++){
        *(newcture + i) = *((*cture) + i);
        *(newCals + i) = *((*(ColInRows)) + i);
    }
    *(newcture + rowNumber + 1) = (int*)malloc(howManyElements * sizeof(int));
    *(newCals + rowNumber + 1) = howManyElements;
    for(i = rowNumber + 2; i <= *rows; i++){
        *(newcture + i) = *(*(cture + i - 1));
        *(newCals + i) = *(*(ColInRows) + i - 1);
    }
    free(*cture);
    *cture = newcture;
    free(*ColInRows);
    *ColInRows = newCals;
    *rows += 1;
}

void insertBeforeColumn(int*** c, int* r, int** cl, int hME, int colNum) {
    int i;
    hME = hME > *r ? *r : hME;
    for (i = 0; i < hME; i++) {
        int currentCols = *(*cl + i);
        int newSize = currentCols + 1;
        int* newC = malloc(newSize * sizeof(int));
        int j;
        for (j = 0; j < newSize; j++) {
            if (j == colNum) {
                *(newC + j) = 0;
            } else if (j < colNum) {
                *(newC + j) = *(*(*c + i) + j);
            } else {
                *(newC + j) = *(*(*c + i) + (j - 1));
            }
        }
        *(*cl + i) = newSize;
        free(*(*c + i));
        *(*c + i) = newC;
    }
}

void insertAfterColumn (int*** cture, int* rows, int** ColInRows, int howManyElements, int columnNumber) {// do edycji
    if(howManyElements <= 0 ) return;
    int ilerows;
    if(howManyElements > *rows){
        ilerows = *rows;
    }
    else
        ilerows = howManyElements;
    int i;
    for(i = 0; i < ilerows; i++){
        int* newRow = (int*)malloc(*(*ColInRows + i + 1) * sizeof(int));
        int ileprzed;
        if(columnNumber < *(*ColInRows + i)){
            ileprzed = columnNumber;
        }
        else
            ileprzed = *(*ColInRows + i);
        int j;
        for(j = 0; j <= ileprzed; j++){
            *(newRow + j) = *(*(*cture + i) + j);
        }
        *(newRow + ileprzed + 1) = 0;
        for(j = ileprzed + 2; j < *(*ColInRows + i); j++){ //potencjalny blad
            *(newRow + j) = *(*(*cture + i) + j - 1);
        }
        *(*ColInRows + i) += 1;
        free(*(*cture + i));
        *(*cture + i) = newRow;
    }
}

void deleteRow (int*** cture, int* rows, int** ColInRows, int row) {
    if((*rows) <= row || (*rows) < 1) return;
    int **Newcture = (int**)malloc((*rows - 1) * sizeof(int*));
    int *NowyWskaznikDoKazdegoWiersza = (int*)malloc((*rows - 1) * sizeof(int));
    int i;
    for( i = 0; i < row; i++){
        *(Newcture + i) = *((*cture) + i);
        *(NowyWskaznikDoKazdegoWiersza + i) = *(*(ColInRows) + i);
    }
    for(i = row; i < *rows - 1; i++){
        *(Newcture + i) = *((*cture) + i + 1);
        *(NowyWskaznikDoKazdegoWiersza + i) = *(*(ColInRows) + i + 1);
    }
    free(*(*(cture)+ row));
    free(*cture);
    free(*ColInRows);
    *ColInRows = NowyWskaznikDoKazdegoWiersza;
    *cture = Newcture;
    *rows -= 1;
}

void deleteFirstColumn (int*** cture, int* rows, int** ColInRows) {
    int i = 0;
    while (i < *rows) {
        int current_cols = *(*ColInRows + i);

        if (current_cols > 1) {
            int j;
            for ( j = 0; j < current_cols - 1; j++) {
                *(*(*cture + i) + j) = *(*(*cture + i) + j + 1);
            }
            int* resized = realloc(*(*cture + i), (current_cols - 1) * sizeof(int));
            if (!resized) exit(1);
            *(*cture + i) = resized;
            *(*ColInRows + i) -= 1;
            i++;
        }
        else {

            free(*(*cture + i));
            int j;
            for ( j = i; j < *rows - 1; j++) {
                *(*cture + j) = *(*cture + j + 1);
                *(*ColInRows + j) = *(*ColInRows + j + 1);
            }

            (*rows)--;

            if (*rows > 0) {
                *cture = realloc(*cture, (*rows) * sizeof(int*));
                *ColInRows = realloc(*ColInRows, (*rows) * sizeof(int));
            } else {
                free(*cture);
                free(*ColInRows);
                *cture = NULL;
                *ColInRows = NULL;
            }
        }
    }
}
void deleteLastColumn (int*** cture, int* rows, int** ColInRows) {
        int i = 0;
        while (i < *rows) {
            int current_cols = *(*ColInRows + i);

            if (current_cols > 1) {

                int* resized = realloc(*(*cture + i), (current_cols - 1) * sizeof(int));
                if (!resized) exit(1);
                *(*cture + i) = resized;
                *(*ColInRows + i) -= 1;
                i++;
            }
            else {
                free(*(*cture + i));
                int j;
                for ( j = i; j < *rows - 1; j++) {
                    *(*cture + j) = *(*cture + j + 1);
                    *(*ColInRows + j) = *(*ColInRows + j + 1);
                }

                (*rows)--;

                if (*rows > 0) {
                    *cture = realloc(*cture, (*rows) * sizeof(int*));
                    *ColInRows = realloc(*ColInRows, (*rows) * sizeof(int));
                } else {
                    free(*cture);
                    free(*ColInRows);
                    *cture = NULL;
                    *ColInRows = NULL;
                }
            }
        }

}

void removeColumn (int*** cture, int* rows, int** ColInRows, int column) {
    int i;
    for(i = 0; i < *rows; i++){
        if(column < *(*ColInRows + i)){
            if(*(*ColInRows + i) > 1){
                int j;
                for(j = column; j < *(*ColInRows + i) - 1; j++){
                    *(*(*cture + i) + j) = *(*(*cture + i) + j + 1);
                }
                *(*cture + i) = (int*)realloc(*(*cture + i), (*(*ColInRows + i) - 1) * sizeof(int));
                *(*ColInRows + i) -= 1;
            }
            else {
                free(*(*cture + i));
                int k;
                for(k = i; k < *rows - 1; k++){
                    *(*cture + k) = *(*cture + k + 1);
                    *(*ColInRows + k) = *(*ColInRows + k + 1);
                }
                *rows -= 1;
                if(*rows > 0){
                    *cture = (int**)realloc(*cture, *rows * sizeof(int*));
                    *ColInRows = (int*)realloc(*ColInRows, *rows * sizeof(int));
                }
                else {
                    free(*cture);
                    free(*ColInRows);
                    *cture = NULL;
                    *ColInRows = NULL;
                }
                i--;
            }
        }
    }
}




void afr(int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements) {
    addFrontRow(cture,rows, ColInRows, howManyElements);
    int i;
    for(i = 0; i < howManyElements; i++){
        *(*(*(cture)+ 0) + i) = *(elements + i);
    }
}


void afc (int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements) {
    int dodatkowepoczatki = 0;
    if(howManyElements > *rows){
        dodatkowepoczatki = howManyElements - *rows;
        howManyElements = *rows;
    }
    addFirstColumn(cture, rows, ColInRows, howManyElements);
    int i;
    for( i = 0; i < howManyElements; i++){
        *(*(*(cture) + i) + 0) = *(elements + i);
    }
    for(i = howManyElements; i < howManyElements + dodatkowepoczatki; i++){
        int *nowe = (int*)malloc(1 * sizeof(int));
        *nowe = *(elements + i);
        alr(cture, rows, ColInRows, nowe, 1);
        free(nowe);
    }
}
void alc (int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements) {
    int dodatkowepoczatki = 0;
    if(howManyElements > *rows){
        dodatkowepoczatki = howManyElements - *rows;
        howManyElements = *rows;
    }
    addLastColumn(cture, rows, ColInRows, howManyElements);
    int i;
    for(i = 0; i < howManyElements; i++){
        *(*(*(cture) + i) + (*((*ColInRows) + i) - 1)) = *(elements + i);
    }
    for(i = howManyElements; i < howManyElements + dodatkowepoczatki; i++){
        int *nowe = (int*)malloc(1 * sizeof(int));
        *nowe = *(elements + i);
        alr(cture, rows, ColInRows, nowe, 1);
        int lastRowIndex = *rows - 1;
        int lastColumnIndex = *((*ColInRows) + lastRowIndex) - 1;
        *(*(*(cture) + lastRowIndex) + lastColumnIndex) = *nowe;
        free(nowe);
    }
}
void ibr (int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements, int rowNumber) {
    if(rowNumber >= *rows) return;
    insertBeforeRow(cture, rows, ColInRows, howManyElements, rowNumber);
    int i;
    for(i = 0; i < howManyElements; i++){
        *(*(*(cture) + rowNumber) + i) = *(elements + i);
    }
}

void iar (int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements, int rowNumber) {
    if(rowNumber >= *rows) return;
    insertAfterRow(cture, rows, ColInRows, howManyElements, rowNumber);
    int i;
    for(i = 0; i < howManyElements; i++){
        *(*(*(cture) + rowNumber + 1) + i) = *(elements + i);
    }
}


void ibc (int*** stukture, int* rows, int** cols, int* elements, int howManyElements, int columnNumber) {
    int i;
    insertBeforeColumn(stukture, rows, cols, howManyElements, columnNumber);
    for (i = 0; i < howManyElements; i++) {
        if (i >= *rows) {
            int* element = malloc(sizeof(int));
            *element = *(elements + i);
            alr(stukture, rows, cols, element, 1);
            free(element);
        } else {
            if (*(*(cols) + i) - 1 > columnNumber) {
                *(*(*(stukture) + i ) + columnNumber) = *(elements + i);
            } else {
                *(*(*(stukture) + i ) + (*(*(cols) + i)) - 1) = *(elements + i);
            }
        }
    }
}

void iac (int*** cture, int* rows, int** ColInRows, int* elements, int howManyElements, int columnNumber) {
    if (howManyElements <= 0) return;
    int affectedRows = (howManyElements > *rows) ? *rows : howManyElements;
    int i, elementIndex;

    for (i = 0, elementIndex = 0; i < affectedRows; i++, elementIndex++) {
        int currentCols = *(*ColInRows + i);
        int insertPosition = columnNumber + 1;

        if (insertPosition <= currentCols) {
            int newSize = currentCols + 1;
            int* newRow = (int*)malloc(newSize * sizeof(int));
            int j;
            for (j = 0; j < insertPosition; j++) {
                *(newRow + j) = *(*(*cture + i) + j);
            }
            *(newRow + insertPosition) = *(elements + elementIndex);
            for (j = insertPosition; j < currentCols; j++) {
                *(newRow + j + 1) = *(*(*cture + i) + j);
            }

            free(*(*cture + i));
            *(*cture + i) = newRow;
            *(*ColInRows + i) = newSize;
        } else {
            int newSize = currentCols + 1;
            int* newRow = (int*)malloc(newSize * sizeof(int));
            int j;
            for (j = 0; j < currentCols; j++) {
                *(newRow + j) = *(*(*cture + i) + j);
            }
            *(newRow + currentCols) = *(elements + elementIndex);
            free(*(*cture + i));
            *(*cture + i) = newRow;
            *(*ColInRows + i) = newSize;
        }
    }

    for (i = affectedRows; i < howManyElements; i++) {
        int* newElement = (int*)malloc(1 * sizeof(int));
        *newElement = *(elements + i);
        alr(cture, rows, ColInRows, newElement, 1);
        int lastRowIndex = *rows - 1;
        int lastColIndex = *(*ColInRows + lastRowIndex) - 1;
        if (columnNumber + 1 < *(*ColInRows + lastRowIndex)) {
            *(*(*(cture) + lastRowIndex) + columnNumber + 1) = *newElement;
        } else {
            *(*(*(cture) + lastRowIndex) + lastColIndex) = *newElement;
        }
        free(newElement);
    }
}

void swr (int*** cture, int* rows, int** ColInRows, int firstRow, int secondRow) {
    if(*rows <= firstRow || *rows <= secondRow || secondRow == firstRow) return;
    int* zamiana = *(*(cture) + firstRow);
    *(*(cture) + firstRow) = *(*(cture) + secondRow);
    *(*(cture) + secondRow) = zamiana;
    int zamien = *(*(ColInRows) + firstRow);
    *(*(ColInRows) + firstRow) = *(*(ColInRows) + secondRow);
    *(*(ColInRows) + secondRow) = zamien;
}

void swc (int*** cture, int* rows, int** ColInRows, int firstColumn, int secondColumn) {
    int i;
    for(i = 0; i < *rows; i++){
        if(firstColumn < *(*ColInRows + i) &&  secondColumn < *(*ColInRows + i)){
            int pomocnicza = *(*(*cture + i)+ firstColumn);
            *(*(*cture + i)+ firstColumn) = *(*(*cture + i)+ secondColumn);
            *(*(*cture + i)+ secondColumn) = pomocnicza;
        }
    }
}

void dfr (int*** cture, int* rows, int** ColInRows) {
    deleteRow(cture, rows, ColInRows, 0);
}

void dlr (int*** cture, int* rows, int** ColInRows) {
    deleteRow(cture, rows, ColInRows, *rows - 1);
}

void dfc (int*** cture, int* rows, int** ColInRows) {
    deleteFirstColumn(cture, rows, ColInRows);
}

void dlc (int*** cture, int* rows, int** ColInRows) {
    deleteLastColumn(cture, rows, ColInRows);
}

void rmr (int*** cture, int* rows, int** ColInRows, int row) {
    deleteRow(cture, rows, ColInRows, row);
}

void rmc (int*** cture, int* rows, int** ColInRows , int column) {
    removeColumn(cture, rows, ColInRows, column);
}


void isb(int*** stukture, int* rows, int** cols, int** elements, int rowStart, int columnStart, int rowQty, int columnQty) {
    int row_index, element_row_index, element_col_index;

    for (row_index = rowStart, element_row_index = 0; row_index < rowStart + rowQty; row_index++, element_row_index++) {
        int col_index, original_col_index;
        if (row_index < *rows) {
            int existing_cols = *(*(cols) + row_index);
            int new_cols = existing_cols + columnQty;
            int* row = (int*)malloc(new_cols * sizeof(int));
            int insert_pos = (columnStart >= existing_cols) ? existing_cols : columnStart;

            for (col_index = 0, original_col_index = 0, element_col_index = 0; col_index < new_cols; col_index++) {
                if (col_index >= insert_pos && col_index < insert_pos + columnQty) {
                    *(row + col_index) = *(*(elements + element_row_index) + element_col_index);
                    element_col_index++;
                } else {
                    *(row + col_index) = *(*(*(stukture) + row_index) + original_col_index);
                    original_col_index++;
                }
            }
            *(*(cols) + row_index) = new_cols;
            free(*(*(stukture) + row_index));
            *(*(stukture) + row_index) = row;
        } else {
            alr(stukture, rows, cols, *(elements + element_row_index), columnQty);
        }
    }
}

void rmb(int*** stukture, int* rows, int** cols, int rowStart, int columnStart, int rowQty, int columnQty) {
    int row_index, original_row_index;
    int last_row = (*rows < rowStart + rowQty) ? *rows : rowStart + rowQty;

    for (row_index = rowStart, original_row_index = rowStart; original_row_index < last_row; row_index++, original_row_index++) {
        int col_index, original_col_index;
        int current_cols = *(*(cols) + row_index);

        if (columnStart < current_cols) {
            int last_col = (current_cols < columnStart + columnQty) ? current_cols : columnStart + columnQty;
            int removed_cols = last_col - columnStart;

            if (current_cols - removed_cols > 0) {
                int new_cols = current_cols - removed_cols;
                int* row = (int*)malloc(new_cols * sizeof(int));

                for (col_index = 0; col_index < columnStart; col_index++) {
                    *(row + col_index) = *(*(*(stukture) + row_index) + col_index);
                }
                for (col_index = columnStart + columnQty, original_col_index = columnStart; col_index < current_cols; col_index++, original_col_index++) {
                    *(row + original_col_index) = *(*(*(stukture) + row_index) + col_index);
                }

                *(*(cols) + row_index) = new_cols;
                free(*(*(stukture) + row_index));
                *(*(stukture) + row_index) = row;
            } else {
                rmr(stukture, rows, cols, row_index);
                row_index--;
            }
        }
    }
}
void prt(int** cture, int*rows, int* ColInRows) {
    printf("%d\n",*rows);
    int i, j;
    if (cture != NULL || rows != 0) {
        for (i = 0; i < *rows; i++) {
            printf("%d ",*(ColInRows + i));
            for (j = 0; j < *(ColInRows + i); j++) {
                printf("%d", *(*(cture + i) + j));
                if (j+1 < *(ColInRows + i) ) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}
void wrf(int*** cture, int *rows, int** ColInRows, char* nazwa) {
    FILE* file = fopen(nazwa, "wb");
    if(file == NULL) {
        return;
    }

    fprintf(file, "%d\n", *rows);
    int i;
    for( i = 0; i < *rows; i++) {
        unsigned char pomBajty1 = ((*(*ColInRows + i)) >> 8) & 0xFF;
        unsigned char pomBajty2 = (*(*ColInRows + i)) & 0xFF;
        fprintf(file, "%c%c", pomBajty1, pomBajty2);

        int j;
        for(j = 0; j < *(*ColInRows + i); j++) {
            int PomKazdaWartosc = *(*(*cture + i) + j);
            unsigned char b1 = (PomKazdaWartosc >> 24) & 0xFF;
            unsigned char b2 = (PomKazdaWartosc >> 16) & 0xFF;
            unsigned char b3 = (PomKazdaWartosc >> 8) & 0xFF;
            unsigned char b4 = PomKazdaWartosc & 0xFF;
            fprintf(file, "%c%c%c%c", b1, b2, b3, b4);
        }
    }

    fclose(file);
}

void rdf(int*** cture, int *rows, int** ColInRows, char* nazwa) {
    if(*cture != NULL) {
        int i;
        for(i = 0; i < *rows; i++) {
            free(*(*cture + i));
        }
        free(*cture);
        free(*ColInRows);
        *rows = 0;
        *cture = NULL;
        *ColInRows = NULL;
    }

    FILE* file = fopen(nazwa, "rb");
    if(file == NULL) {
        return;
    }

    if(fscanf(file, "%d\n", rows) != 1) {
        fclose(file);
        return;
    }

    *cture = (int**)malloc(*rows * sizeof(int*));
    *ColInRows = (int*)malloc(*rows * sizeof(int));


    int i;
    for( i = 0; i < *rows; i++) {
        unsigned char p1, p2;
        if(fscanf(file, "%c%c", &p1, &p2) != 2) {
            int k;
            for( k = 0; k < i; k++) {
                free(*(*cture + k));
            }
            free(*cture);
            free(*ColInRows);
            *rows = 0;
            *cture = NULL;
            *ColInRows = NULL;
            fclose(file);
            return;
        }

        *(*ColInRows + i) = ((unsigned short)p1 << 8) | p2;


        *(*cture + i) = (int*)malloc(*(*ColInRows + i) * sizeof(int));
        if(*(*cture + i) == NULL) {
            int k;
            for( k = 0; k < i; k++) {
                free(*(*cture + k));
            }
            free(*cture);
            free(*ColInRows);
            *rows = 0;
            *cture = NULL;
            *ColInRows = NULL;
            fclose(file);
            return;
        }
        int j;
        for( j = 0; j < *(*ColInRows + i); j++) {
            unsigned char b1, b2, b3, b4;
            if(fscanf(file, "%c%c%c%c", &b1, &b2, &b3, &b4) != 4) {
                int k;
                for( k = 0; k <= i; k++) {
                    free(*(*cture + k));
                }
                free(*cture);
                free(*ColInRows);
                *rows = 0;
                *cture = NULL;
                *ColInRows = NULL;
                fclose(file);
                return;
            }

            *(*(*cture + i) + j) = ((int)b1 << 24) | ((int)b2 << 16) | ((int)b3 << 8) | b4;
        }
    }

    fclose(file);
}
int main() {
    int* rows = malloc(sizeof(int));
    *rows = 0;
    int* ColInRows = malloc(*rows * sizeof(int));
    int** cture = (int**)malloc(*rows * sizeof(int*));
    char* operation = malloc(4 * sizeof(char));

    scanf("%s", operation);
    while (compare(operation, "END") == 0) {
        if (compare(operation, "AFR") == 1) {
            int Elements;
            scanf("%i", &Elements);
            if ( Elements > 0 )
            {
                int i;
                int* elements = malloc(Elements * sizeof(int));
                for (i = 0; i < Elements; i++) {
                    scanf("%i", elements + i);
                }
                afr(&cture, rows, &ColInRows, elements, Elements);
                free(elements);
            }
        }
        else if (compare(operation, "ALR") == 1) {
            int Elements;
            scanf("%i", &Elements);
            if ( Elements > 0 ) {
                int i;
                int *elements = malloc(Elements * sizeof(int));
                for (i = 0; i < Elements; i++) {
                    scanf("%i", elements + i);
                }
                alr(&cture, rows, &ColInRows, elements, Elements);
                free(elements);
            }
        }
        else if (compare(operation, "AFC") == 1) {
            int howMuchElements;
            scanf("%i", &howMuchElements);
            int i;
            int* elements = malloc(howMuchElements * sizeof(int));
            for (i = 0; i < howMuchElements; i++) {
                scanf("%i", elements + i);
            }
            afc(&cture, rows, &ColInRows, elements, howMuchElements);
            free(elements);
        }
        else if (compare(operation, "ALC") == 1) {
            int howMuchElements;
            scanf("%i", &howMuchElements);
            int i;
            int* elements = malloc(howMuchElements * sizeof(int));
            for (i = 0; i < howMuchElements; i++) {
                scanf("%i", elements + i);
            }
            alc(&cture, rows, &ColInRows, elements, howMuchElements);
            free(elements);
        }
        else if (compare(operation, "IBR") == 1) {
            int rowNumber;
            scanf("%i", &rowNumber);
            int howMuchElements;
            scanf("%i", &howMuchElements);
            int i;
            int* elements = malloc(howMuchElements * sizeof(int));
            for (i = 0; i < howMuchElements; i++) {
                scanf("%i", elements + i);
            }
            ibr(&cture, rows, &ColInRows, elements, howMuchElements, rowNumber);
            free(elements);
        }
        else if (compare(operation, "IAR") == 1) {
            int rowNumber;
            scanf("%i", &rowNumber);
            int howMuchElements;
            scanf("%i", &howMuchElements);
            int i;
            int* elements = malloc(howMuchElements * sizeof(int));
            for (i = 0; i < howMuchElements; i++) {
                scanf("%i", elements + i);
            }
            iar(&cture, rows, &ColInRows, elements, howMuchElements, rowNumber);
            free(elements);
        }
        else if (compare(operation, "IBC") == 1) {
            int columnNumber;
            scanf("%i", &columnNumber);
            int howMuchElements;
            scanf("%i", &howMuchElements);
            int i;
            int* elements = malloc(howMuchElements * sizeof(int));
            for (i = 0; i < howMuchElements; i++) {
                scanf("%i", elements + i);
            }
            ibc(&cture, rows, &ColInRows, elements, howMuchElements, columnNumber);
            free(elements);
        }
        else if (compare(operation, "IAC") == 1) {
            int columnNumber;
            scanf("%i", &columnNumber);
            int howMuchElements;
            scanf("%i", &howMuchElements);
            int i;
            int* elements = malloc(howMuchElements * sizeof(int));
            for (i = 0; i < howMuchElements; i++) {
                scanf("%i", elements + i);
            }
            iac(&cture, rows, &ColInRows, elements, howMuchElements, columnNumber);
            free(elements);
        }
        else if (compare(operation, "SWR") == 1) {
            int firstRow;
            scanf("%i", &firstRow);
            int secondRow;
            scanf("%i", &secondRow);
            swr(&cture, rows, &ColInRows, firstRow, secondRow);
        }
        else if (compare(operation, "SWC") == 1) {
            int firstColumn;
            scanf("%i", &firstColumn);
            int secondColumn;
            scanf("%i", &secondColumn);
            swc(&cture, rows, &ColInRows, firstColumn, secondColumn);
        }
        else if (compare(operation, "DFR") == 1) {
            dfr(&cture, rows, &ColInRows);
        }
        else if (compare(operation, "DLR") == 1) {
            dlr(&cture, rows, &ColInRows);
        }
        else if (compare(operation, "DFC") == 1) {
            dfc(&cture, rows, &ColInRows);
        }
        else if (compare(operation, "DLC") == 1) {
            dlc(&cture, rows, &ColInRows);
        }
        else if (compare(operation, "RMR") == 1) {
            int row;
            scanf("%i", &row);
            rmr(&cture, rows, &ColInRows, row);
        }
        else if (compare(operation, "RMC") == 1) {
            int column;
            scanf("%i", &column);
            rmc(&cture, rows, &ColInRows, column);
        }
        else if (compare(operation, "ISB") == 1) {
            int rowStart;
            scanf("%i", &rowStart);
            int columnStart;
            scanf("%i", &columnStart);
            int rowQty;
            scanf("%i", &rowQty);
            int columnQty;
            scanf("%i", &columnQty);
            int i;
            int** elements = (int**)malloc(rowQty * sizeof(int*));
            for (i = 0; i < rowQty; i++) {
                *(elements + i) = (int*)malloc(columnQty * sizeof(int));
                int j;
                for (j = 0; j < columnQty; j++) {
                    scanf("%i", (*(elements + i) + j));
                }
            }
            isb(&cture, rows, &ColInRows, elements, rowStart, columnStart, rowQty, columnQty);
            for (i = 0; i < rowQty; i++) {
                free(*(elements + i));
            }
            free(elements);
        }
        else if (compare(operation, "RMB") == 1) {
            int rowStart;
            scanf("%i", &rowStart);
            int rowQty;
            scanf("%i", &rowQty);
            int columnStart;
            scanf("%i", &columnStart);
            int columnQty;
            scanf("%i", &columnQty);
            rmb(&cture, rows, &ColInRows, rowStart, columnStart, rowQty, columnQty);
        }
        else if (compare(operation, "WRF") == 1) {
            char* nazwa = (char*)malloc(17 * sizeof(char));;
            scanf("%s", nazwa);
            wrf(&cture, rows, &ColInRows, nazwa);
            free(nazwa);
        }
        else if (compare(operation, "RDF") == 1) {
            char* nazwa = (char*)malloc(17 * sizeof(char));
            scanf("%s", nazwa);
            rdf(&cture, rows, &ColInRows, nazwa);
            free(nazwa);//chyba tak
        }
        else if (compare(operation, "PRT") == 1) {
            prt(cture, rows, ColInRows);
        }
        fflush(stdin);
        scanf("%s", operation);
    }
    while (*rows > 0) {
        dfr(&cture, rows, &ColInRows);
    }
    free(cture);
    free(operation);
    free(rows);
    free(ColInRows);
    return 0;
}
