# StateMachine
Libreria arduino para para simular una maquina de estados finitos.

## Cómo usar
Se crea una instancia de la clase.

```
StateMachine machine = StateMachine();
```

En `setup` se llama la función `changeState` para definir el caso inicial.

```
machine.changeState("firstCase");
```

En `loop` se llama la función `stateCase` para cada uno de los casos que se tendrá pasando la función que se ejecutará.

```
machine.stateCase("firstCase",firstFunction);
machine.stateCase("secondCase",secondFunction);
...
...
```

Se debe crear una función para cada caso.

Para cambiar de un caso a otro se debe llamar la función `changeState()` y pasandole como parametro el caso al que se quiere cambiar.

## Funciones
```StateMachine()```
Constructor de la clase.

```void changeState("caso")```
Esta función hace que cambie el caso que se esta ejecutando.

```void stateCase("caso",funcion)```
Esta función agrega cada uno de los casos y ejecuta la funcion correspondiente del caso activado.

## License
Copyright (c) 2019 Erick R Garcia Martinez.
Licensed under [Apache license, version2.0](LICENSE).
