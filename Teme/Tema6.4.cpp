#include <iostream>
#include <string>

using namespace std;

// Funcție pentru decriptarea unui caracter folosind cifrul Vigenère
char decryptChar(char cipherChar, char keyChar) {
    char baseChar = ' ';
    int alphabetSize = 69; // Lungimea alfabetului extins

    if (isalpha(cipherChar)) {
        baseChar = isupper(cipherChar) ? 'A' : 'a';
    } else {
        baseChar = '0';
    }

    int cipherValue = cipherChar - baseChar;
    int keyValue = keyChar - ' ';

    int decryptedValue = (cipherValue - keyValue + alphabetSize) % alphabetSize;

    return baseChar + decryptedValue;
}

// Funcție pentru decriptarea unui mesaj folosind cifrul Vigenère
string decryptVigenere(const string& cipherText, const string& key) {
    string decryptedText;
    int keyLength = key.length();
    int textLength = cipherText.length();
    
    for (int i = 0; i < textLength; ++i) {
        char cipherChar = cipherText[i];
        char keyChar = key[i % keyLength];
        
        decryptedText += decryptChar(cipherChar, keyChar);
    }
    
    return decryptedText;
}

int main() {
    string cipherText = "TQmysfsAbys4)!o9If2km6Iy7Ai2u-5A).Estm)6R-8Pf:Eq3!)?Riukjysxs!i1ErHkr)E-5Ak!VzJur(Rj.ArRWnJQkysuuJq.Y-tNX0YqLkcyGf3');Ew9A)1VjqLqysqqkX(EstKfQsf5KfRQfykw-Ew1AX(shqPb-EAJ'bRMssQfyQ-5A)1VfsQiRMsJBr)Hz1kp!MtqHk2MAJ-rRFz1?r0M-1!)4Ywqj),xf5KfTsm(Oq6YqyQZUsxykb?sn3kp!MtqHkyu-tA,ysh(Br)Hz1m),E-5Nf)H-5A)1VfsQiRHjJQkRTnsEl.u-s!Z6sf8!))I-uNXRSgy-b6YqJOXRJfsAjRPfJOZyPiqP;RHjJLbRGf3')YHf2p-yFft!jSsI(LXREx9!;RQfJIX6sh(Br)Hf2ka2sy7AfRSwykf)swqJaTsuuJq.Y-j!qyPAJLb)Xw(kC6YqJOfR2zxQiR!kqJqTsxykf)GD4kayXfJLb)Xw(k?(MsKk?;SnJIXRXwqCbyQ-yJZ2Xn8KoRTjOK)0Sf8PXTsqqkjyVlyJbysgqHq6MAJ-X!srykq6xnJIl.Ss(H;RWnJIXRYn9!jRTjJBr.MxJ-r(sxukg:EhqkX;E-sQ);MhyKo?Wj1A)0IqukjyRi7A)yPjJQk:V-vAq2shukd5Mqu!rRTf3VXRHn3kp?Wz1kj2Y'J3X6sk7Qj:W-1QZ.Y-3EZ6shqkp2srqE);Sf9A;RGwu' R?tqPbREhuOq2E-1A);Vn)AXRFnqPXRQf2!;RYn9!qysh(kjyMsyHbRWzrOr:Ewqm)0YrJA):Qz1kk2GfzEqTsiuka?TfJQkRHf2?)1MsJLo?RiLkX;VtqLbRHjJIf)I'JuX.sj(kkWS-)Aa2ErJLbRHf3OXTshq-fRIwqI)6R-9NbyFfKkf)sy4Pr9YnJPl!u-qkc6sy7AZ?X-1!)(Mo1KZRZw4kg?Qf9!q2siukZ2ExLkZyX-qkwyFt)EqRQf2!)yGt1K;RQfyks.S-9Nb6xuqPo?siukZyRiJBr4MxuI)1IDq-X,EAJO,yV-vE)!VjrQf!sxqkf)GjqLXRE-2E),I-5Qk2sx4!o2PjJ'o2TyJEk6QfLka?TfJ-r(sxukw6GjLkZyGnJAoysy7AZ?X-tA)yQnqVXSsn3OXRIzLkf)sx9!o2E-yJ)0EwukjysfvHX(u-vEf)H-sQm.Ms8ka2skuNf0Mwum)?MyqOb(shqkjyM-9NX6Ixskm2sq(IbUsn3kp3Ew8EqTsrqIXTshqP)2VfJAXRHjJPX.I-tA)0EuLka2sqqklRZwuIbRTnuNa2swq?ayVjqkp6s0yJbRXn5Pf9u-yJ)-EwvQiRHjwAq2Pt7m);I-1!),Tf9Ai2sruHbTshqJaRQfJQf!ErJHXRJj9A;RGz2ksysx5QkTsn2E)6E-9KX!I-x!f)Iqukc.Yr(Ob9siukm2srqH),M-";
    string key = "yourkey"; // Inlocuieste cu cheia ta

    string decryptedText = decryptVigenere(cipherText, key);
    cout << "Mesajul decriptat: " << decryptedText << endl;

    return 0;
}
