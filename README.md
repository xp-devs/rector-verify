# Rector for Codeception Verify

This project lets you migrate from PHPUnit assertions to BDD style assertions [Codeception/Verify](https://github.com/Codeception/Verify) 
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

- toEqual
- notToEqual
- toBe
- notToBe
- toBeInstanceOf
- notToBeInstanceOf
- arrayToHaveCount
- arrayNotToHaveCount
- toBeGreaterThan
- toBeGreaterThanOrEqualTo
- toBeLessThan
- toBeLessThanOrEqualTo
- arrayToContainOnlyInstancesOf
- arrayToHaveKey
- arrayNotToHaveKey
- toBeTrue
- notToBeTrue
- toBeFalse
- notToBeFalse
- toBeNull
- notToBeNull
- toBeEmpty
- notToBeEmpty
- toBeArray
- toBeBool
- toBeFloat
- toBeInt
- toBeNumeric
- toBeObject
- toBeResource
- toBeString
- toBeScalar
- toBeCallable
- toBeIterable
- notToBeArray
- notToBeBool
- notToBeFloat
- notToBeInt
- notToBeNumeric
- notToBeObject
- notToBeResource
- notToBeString
- notToBeScalar
- notToBeCallable
- notToBeIterable

## License

The MIT License (MIT). Please see [License File](LICENSE) for more information.
