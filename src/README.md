# How to run `studentData.ts`:
There is one thing you will need before you are able to run the code in `studentData.ts`:
- [NodeJS](https://nodejs.org/en/download/) installed. 
  - You need NPM in order to setup TypeScript on your machine.

After having NodeJS, you will be able to use `npm` *(Node Package Manager)*. This will allow you to install TypeScript by executing the following command:

```bash
npm install -g typescript
```

Congratulations! You are now able to run `tsc` the TypeScript compiler.

To run the file, simply use this command in the project **root** folder:

```bash
tsc src/studentData.ts | node src/studentData.js
```

## Want to overwrite to the student.txt file instead of appending?
Simply switch this line:

```ts
fs.appendFileSync('students.txt', `${studentData.firstName} ${studentData.lastName} ${studentData.mNumber}\n`);
```

to:

```ts
fs.writeFileSync('students.txt', `${studentData.firstName} ${studentData.lastName} ${studentData.mNumber}\n`);
```
