function checkStrings(s1: string, s2: string): boolean {
    let first_part_s1: string[] = [];
    let second_part_s1: string[] = [];
    let first_part_s2: string[] = [];
    let second_part_s2: string[] = [];

    for(let i = 0; i < s1.length; i++){
        if(i & 1){
            first_part_s1.push(s1[i]);
        } else {
            second_part_s1.push(s1[i]);
        }
    }

    for(let i = 0; i < s2.length; i++){
        if(i & 1){
            first_part_s2.push(s2[i]);
        } else {
            second_part_s2.push(s2[i]);
        }
    }

    first_part_s1.sort();
    second_part_s1.sort();
    first_part_s2.sort();
    second_part_s2.sort();

    return (
        first_part_s1.join('') === first_part_s2.join('') &&
        second_part_s1.join('') === second_part_s2.join('')
    );

};