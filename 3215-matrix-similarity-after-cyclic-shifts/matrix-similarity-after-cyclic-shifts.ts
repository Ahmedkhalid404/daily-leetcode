function areSimilar(mat: number[][], k: number): boolean {
    const n: number = mat.length;
    const m: number = mat[0].length;

    k %= m;

    const tmp: number[][] = structuredClone(mat);
    
    for(let i = 0; i < n; i++){
        for(let l = 0; l < k; l++){
            const firstRkm = mat[i][0];
            for(let j = 1; j < m; j++){
                mat[i][j - 1] = mat[i][j];
            }
            mat[i][m - 1] = firstRkm;
        }
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (mat[i][j] !== tmp[i][j]) return false;
        }
    }

    return true;
};