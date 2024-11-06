def levenshtein_distance(s1, s2):
    if len(s1) < len(s2):
        return levenshtein_distance(s2, s1)

    if len(s2) == 0:
        return len(s1)

    previous_row = range(len(s2) + 1)
    for i, c1 in enumerate(s1):
        current_row = [i + 1]
        for j, c2 in enumerate(s2):
            insertions = previous_row[j + 1] + 1
            deletions = current_row[j] + 1
            substitutions = previous_row[j] + (c1 != c2)
            current_row.append(min(insertions, deletions, substitutions))
        previous_row = current_row

    return previous_row[-1]

def search_with_one_error(text, word):
    word_len = len(word)
    for i in range(len(text) - word_len + 1):
        substring = text[i:i + word_len]
        if levenshtein_distance(substring, word) <= 1:
            return True
    return False


n = int(input())
text = str(input())
r, m = map(int, input().split())

res = 0
for i in range(r):
    word = str(input())
    if search_with_one_error(text, word):
        res+=1

print(res)

# Ejemplo de uso
# text = "a_beces_rompo_cosas"
# word = "a_veces"
# if search_with_one_error(text, word):
#     print(f"La palabra '{word}' se encuentra en el texto con hasta un error permitido.")
# else:
#     print(f"La palabra '{word}' no se encuentra en el texto con hasta un error permitido.")