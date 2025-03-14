# Rector for Codeception Verify

This project lets you migrate from PHPUnit assertions to BDD style
assertions [Codeception/Verify](https://github.com/Codeception/Verify)
using automated refactoring powered by [Rector](https://github.com/rectorphp/rector)

Code before:

```PHP
class GenericEventTest extends TestCase
{
    private GenericEvent $event;
    private \stdClass $subject;

    protected function setUp(): void
    {
        $this->subject = new \stdClass();
        $this->event = new GenericEvent($this->subject, ['name' => 'Event']);
    }

    public function testConstruct()
    {
        $this->assertEquals(new GenericEvent($this->subject, ['name' => 'Event']), $this->event);
    }

    /**
     * Tests Event->getArgs().
     */
    public function testGetArguments()
    {
        // test getting all
        $this->assertSame(['name' => 'Event'], $this->event->getArguments());
    }

    public function testSetArguments()
    {
        $result = $this->event->setArguments(['foo' => 'bar']);
        $this->assertSame(['foo' => 'bar'], $this->event->getArguments());
        $this->assertSame($this->event, $result);
    }
}
```

Code after:

```PHP
class GenericEventTest extends TestCase
{
    private GenericEvent $event;
    private \stdClass $subject;

    protected function setUp(): void
    {
        $this->subject = new \stdClass();
        $this->event = new GenericEvent($this->subject, ['name' => 'Event']);
    }

    public function testConstruct()
    {
        expect($this->event)->toEqual(new GenericEvent($this->subject, ['name' => 'Event']));
    }

    /**
     * Tests Event->getArgs().
     */
    public function testGetArguments()
    {
        // test getting all
        expect($this->event->getArguments())->toBe(['name' => 'Event']);
    }

    public function testSetArguments()
    {
        $result = $this->event->setArguments(['foo' => 'bar']);
        expect($this->event->getArguments())->toBe(['foo' => 'bar']);
        expect($result)->toBe($this->event);
    }
}
```

## Installation

You can install the package as a dev dependency:

```bash
composer require --dev xp-devs/rector-verify
```

## Configuration

Add `AssertionVerifyRector` rule to your Rector config file

```PHP
<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use XpDevs\RectorVerify\AssertionVerifyRector;

return RectorConfig::configure()
    ->withRules([
        AssertionVerifyRector::class,
    ]);
```

## Usage

To see the code migrations that Rector will do, run:

```bash
vendor/bin/rector process --dry-run
```

and when you want to execute the migrations run:

```bash
vendor/bin/rector process
```

## Supports expectations

| PHPUnit                                   | Expect                               |
|-------------------------------------------|--------------------------------------|
| assertEquals                              | toEqual                              |
| assertNotEquals                           | notToEqual                           |
| assertSame                                | toBe                                 |
| assertNotSame                             | notToBe                              |
| assertInstanceOf                          | toBeInstanceOf                       |
| assertNotInstanceOf                       | notToBeInstanceOf                    |
| assertCount                               | arrayToHaveCount                     |
| assertNotCount                            | arrayNotToHaveCount                  |
| assertGreaterThan                         | toBeGreaterThan                      |
| assertGreaterThanOrEqual                  | toBeGreaterThanOrEqualTo             |
| assertLessThan                            | toBeLessThan                         |
| assertLessThanOrEqual                     | toBeLessThanOrEqualTo                |
| assertContainsOnlyInstancesOf             | arrayToContainOnlyInstancesOf        |
| assertArrayHasKey                         | arrayToHaveKey                       |
| assertArrayNotHasKey                      | arrayNotToHaveKey                    |
| assertNotContains                         | arrayNotToContain                    |
| assertNotContainsEquals                   | arrayNotToContainEqual               |
| assertNotContainsOnly                     | arrayNotToContainOnly                |
| assertNotSameSize                         | arrayNotToHaveSameSizeAs             |
| assertContains                            | arrayToContain                       |
| assertContainsEquals                      | arrayToContainEqual                  |
| assertContainsOnly                        | arrayToContainOnly                   |
| assertSameSize                            | arrayToHaveSameSizeAs                |
| assertObjectNotHasProperty                | baseObjectNotToHaveProperty          |
| assertObjectHasProperty                   | baseObjectToHaveProperty             |
| assertJsonFileNotEqualsJsonFile           | jsonFileNotToEqualJsonFile           |
| assertJsonFileEqualsJsonFile              | jsonFileToEqualJsonFile              |
| assertJsonStringNotEqualsJsonFile         | jsonStringNotToEqualJsonFile         |
| assertJsonStringNotEqualsJsonString       | jsonStringNotToEqualJsonString       |
| assertJsonStringEqualsJsonFile            | jsonStringToEqualJsonFile            |
| assertJsonStringEqualsJsonString          | jsonStringToEqualJsonString          |
| assertXmlFileNotEqualsXmlFile             | xmlFileNotToEqualXmlFile             |
| assertXmlFileEqualsXmlFile                | xmlFileToEqualXmlFile                |
| assertXmlStringNotEqualsXmlFile           | xmlStringNotToEqualXmlFile           |
| assertXmlStringNotEqualsXmlString         | xmlStringNotToEqualXmlString         |
| assertXmlStringEqualsXmlFile              | xmlStringToEqualXmlFile              |
| assertXmlStringEqualsXmlString            | xmlStringToEqualXmlString            |
| assertStringNotContainsString             | stringNotToContainString             |
| assertStringNotContainsStringIgnoringCase | stringNotToContainStringIgnoringCase |
| assertStringEndsNotWith                   | stringNotToEndWith                   |
| assertStringNotEqualsFile                 | stringNotToEqualFile                 |
| assertStringNotEqualsFileCanonicalizing   | stringNotToEqualFileCanonicalizing   |
| assertStringNotEqualsFileIgnoringCase     | stringNotToEqualFileIgnoringCase     |
| assertStringNotMatchesFormat              | stringNotToMatchFormat               |
| assertStringNotMatchesFormatFile          | stringNotToMatchFormatFile           |
| assertDoesNotMatchRegularExpression       | stringNotToMatchRegExp               |
| assertStringStartsNotWith                 | stringNotToStartWith                 |
| assertJson                                | stringToBeJson                       |
| assertStringContainsString                | stringToContainString                |
| assertStringContainsStringIgnoringCase    | stringToContainStringIgnoringCase    |
| assertStringEndsWith                      | stringToEndWith                      |
| assertStringEqualsFile                    | stringToEqualFile                    |
| assertStringEqualsFileCanonicalizing      | stringToEqualFileCanonicalizing      |
| assertStringEqualsFileIgnoringCase        | stringToEqualFileIgnoringCase        |
| assertStringMatchesFormat                 | stringToMatchFormat                  |
| assertStringMatchesFormatFile             | stringToMatchFormatFile              |
| assertMatchesRegularExpression            | stringToMatchRegExp                  |
| assertStringStartsWith                    | stringToStartWith                    |
| assertNotEqualsCanonicalizing             | notToEqualCanonicalizing             |
| assertNotEqualsIgnoringCase               | notToEqualIgnoringCase               |
| assertEqualsCanonicalizing                | toEqualCanonicalizing                |
| assertEqualsIgnoringCase                  | toEqualIgnoringCase                  |
| assertTrue                                | toBeTrue                             |
| assertNotTrue                             | notToBeTrue                          |
| assertFalse                               | toBeFalse                            |
| assertNotFalse                            | notToBeFalse                         |
| assertNull                                | toBeNull                             |
| assertNotNull                             | notToBeNull                          |
| assertEmpty                               | toBeEmpty                            |
| assertNotEmpty                            | notToBeEmpty                         |
| assertIsArray                             | toBeArray                            |
| assertIsBool                              | toBeBool                             |
| assertIsFloat                             | toBeFloat                            |
| assertIsInt                               | toBeInt                              |
| assertIsNumeric                           | toBeNumeric                          |
| assertIsObject                            | toBeObject                           |
| assertIsResource                          | toBeResource                         |
| assertIsString                            | toBeString                           |
| assertIsScalar                            | toBeScalar                           |
| assertIsCallable                          | toBeCallable                         |
| assertIsIterable                          | toBeIterable                         |
| assertIsNotArray                          | notToBeArray                         |
| assertIsNotBool                           | notToBeBool                          |
| assertIsNotFloat                          | notToBeFloat                         |
| assertIsNotInt                            | notToBeInt                           |
| assertIsNotNumeric                        | notToBeNumeric                       |
| assertIsNotObject                         | notToBeObject                        |
| assertIsNotResource                       | notToBeResource                      |
| assertIsNotString                         | notToBeString                        |
| assertIsNotScalar                         | notToBeScalar                        |
| assertIsNotCallable                       | notToBeCallable                      |
| assertIsNotIterable                       | notToBeIterable                      |
| assertDirectoryIsNotReadable              | directoryNotToBeReadable             |
| assertDirectoryIsNotWritable              | directoryNotToBeWritable             |
| assertDirectoryDoesNotExist               | directoryNotToExist                  |
| assertDirectoryIsReadable                 | directoryToBeReadable                |
| assertDirectoryIsWritable                 | directoryToBeWritable                |
| assertDirectoryExists                     | directoryToExist                     |
| assertFileIsNotReadable                   | fileNotToBeReadable                  |
| assertFileIsNotWritable                   | fileNotToBeWritable                  |
| assertFileDoesNotExist                    | fileNotToExist                       |
| assertFileEquals                          | fileToBeEqual                        |
| assertFileEqualsCanonicalizing            | fileToBeEqualCanonicalizing          |
| assertFileEqualsIgnoringCase              | fileToBeEqualIgnoringCase            |
| assertFileIsReadable                      | fileToBeReadable                     |
| assertFileIsWritable                      | fileToBeWritable                     |
| assertFileExists                          | fileToExist                          |
| assertFileNotEquals                       | fileToNotEqual                       |
| assertFileNotEqualsCanonicalizing         | fileToNotEqualCanonicalizing         |
| assertFileNotEqualsIgnoringCase           | fileToNotEqualIgnoringCase           |
| assertIsNotClosedResource                 | notToBeClosedResource                |
| assertIsClosedResource                    | toBeClosedResource                   |
| assertFinite                              | toBeFinite                           |
| assertInfinite                            | toBeInfinite                         |
| assertNan                                 | toBeNan                              |

## License

The MIT License (MIT). Please see [License File](LICENSE) for more information.
