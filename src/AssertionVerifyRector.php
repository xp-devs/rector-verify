<?php

declare(strict_types=1);

namespace XpDevs\RectorVerify;

use PhpParser\Node;
use PHPStan\Analyser\MutatingScope;
use PHPStan\Type\ThisType;
use PHPUnit\Framework\Assert;
use PHPUnit\Framework\TestCase;
use Rector\Rector\AbstractRector;

class AssertionVerifyRector extends AbstractRector
{
    public const TWO_ARGS_METHODS_MAP = [
        'assertEquals' => 'toEqual',
        'assertNotEquals' => 'notToEqual',
        'assertSame' => 'toBe',
        'assertNotSame' => 'notToBe',
        'assertInstanceOf' => 'toBeInstanceOf',
        'assertNotInstanceOf' => 'notToBeInstanceOf',
        'assertCount' => 'arrayToHaveCount',
        'assertNotCount' => 'arrayNotToHaveCount',
        'assertGreaterThan' => 'toBeGreaterThan',
        'assertGreaterThanOrEqual' => 'toBeGreaterThanOrEqualTo',
        'assertLessThan' => 'toBeLessThan',
        'assertLessThanOrEqual' => 'toBeLessThanOrEqualTo',
        'assertContainsOnlyInstancesOf' => 'arrayToContainOnlyInstancesOf',
        'assertArrayHasKey' => 'arrayToHaveKey',
        'assertArrayNotHasKey' => 'arrayNotToHaveKey',
        'assertNotContains' => 'arrayNotToContain',
        'assertNotContainsEquals' => 'arrayNotToContainEqual',
        'assertNotContainsOnly' => 'arrayNotToContainOnly',
        'assertNotSameSize' => 'arrayNotToHaveSameSizeAs',
        'assertContains' => 'arrayToContain',
        'assertContainsEquals' => 'arrayToContainEqual',
        'assertContainsOnly' => 'arrayToContainOnly',
        'assertSameSize' => 'arrayToHaveSameSizeAs',
        'assertObjectNotHasProperty' => 'baseObjectNotToHaveProperty',
        'assertObjectHasProperty' => 'baseObjectToHaveProperty',
        'assertJsonFileNotEqualsJsonFile' => 'jsonFileNotToEqualJsonFile',
        'assertJsonFileEqualsJsonFile' => 'jsonFileToEqualJsonFile',
        'assertJsonStringNotEqualsJsonFile' => 'jsonStringNotToEqualJsonFile',
        'assertJsonStringNotEqualsJsonString' => 'jsonStringNotToEqualJsonString',
        'assertJsonStringEqualsJsonFile' => 'jsonStringToEqualJsonFile',
        'assertJsonStringEqualsJsonString' => 'jsonStringToEqualJsonString',
        'assertXmlFileNotEqualsXmlFile' => 'xmlFileNotToEqualXmlFile',
        'assertXmlFileEqualsXmlFile' => 'xmlFileToEqualXmlFile',
        'assertXmlStringNotEqualsXmlFile' => 'xmlStringNotToEqualXmlFile',
        'assertXmlStringNotEqualsXmlString' => 'xmlStringNotToEqualXmlString',
        'assertXmlStringEqualsXmlFile' => 'xmlStringToEqualXmlFile',
        'assertXmlStringEqualsXmlString' => 'xmlStringToEqualXmlString',
        'assertStringNotContainsString' => 'stringNotToContainString',
        'assertStringNotContainsStringIgnoringCase' => 'stringNotToContainStringIgnoringCase',
        'assertStringEndsNotWith' => 'stringNotToEndWith',
        'assertStringNotEqualsFile' => 'stringNotToEqualFile',
        'assertStringNotEqualsFileCanonicalizing' => 'stringNotToEqualFileCanonicalizing',
        'assertStringNotEqualsFileIgnoringCase' => 'stringNotToEqualFileIgnoringCase',
        'assertStringNotMatchesFormat' => 'stringNotToMatchFormat',
        'assertStringNotMatchesFormatFile' => 'stringNotToMatchFormatFile',
        'assertDoesNotMatchRegularExpression' => 'stringNotToMatchRegExp',
        'assertStringStartsNotWith' => 'stringNotToStartWith',
        'assertJson' => 'stringToBeJson',
        'assertStringContainsString' => 'stringToContainString',
        'assertStringContainsStringIgnoringCase' => 'stringToContainStringIgnoringCase',
        'assertStringEndsWith' => 'stringToEndWith',
        'assertStringEqualsFile' => 'stringToEqualFile',
        'assertStringEqualsFileCanonicalizing' => 'stringToEqualFileCanonicalizing',
        'assertStringEqualsFileIgnoringCase' => 'stringToEqualFileIgnoringCase',
        'assertStringMatchesFormat' => 'stringToMatchFormat',
        'assertStringMatchesFormatFile' => 'stringToMatchFormatFile',
        'assertMatchesRegularExpression' => 'stringToMatchRegExp',
        'assertStringStartsWith' => 'stringToStartWith',
        'assertNotEqualsCanonicalizing' => 'notToEqualCanonicalizing',
        'assertNotEqualsIgnoringCase' => 'notToEqualIgnoringCase',
        'assertEqualsCanonicalizing' => 'toEqualCanonicalizing',
        'assertEqualsIgnoringCase' => 'toEqualIgnoringCase',
    ];

    public const ONE_ARG_METHODS_MAP = [
        'assertTrue' => 'toBeTrue',
        'assertNotTrue' => 'notToBeTrue',
        'assertFalse' => 'toBeFalse',
        'assertNotFalse' => 'notToBeFalse',
        'assertNull' => 'toBeNull',
        'assertNotNull' => 'notToBeNull',
        'assertEmpty' => 'toBeEmpty',
        'assertNotEmpty' => 'notToBeEmpty',
        'assertIsArray' => 'toBeArray',
        'assertIsBool' => 'toBeBool',
        'assertIsFloat' => 'toBeFloat',
        'assertIsInt' => 'toBeInt',
        'assertIsNumeric' => 'toBeNumeric',
        'assertIsObject' => 'toBeObject',
        'assertIsResource' => 'toBeResource',
        'assertIsString' => 'toBeString',
        'assertIsScalar' => 'toBeScalar',
        'assertIsCallable' => 'toBeCallable',
        'assertIsIterable' => 'toBeIterable',
        'assertIsNotArray' => 'notToBeArray',
        'assertIsNotBool' => 'notToBeBool',
        'assertIsNotFloat' => 'notToBeFloat',
        'assertIsNotInt' => 'notToBeInt',
        'assertIsNotNumeric' => 'notToBeNumeric',
        'assertIsNotObject' => 'notToBeObject',
        'assertIsNotResource' => 'notToBeResource',
        'assertIsNotString' => 'notToBeString',
        'assertIsNotScalar' => 'notToBeScalar',
        'assertIsNotCallable' => 'notToBeCallable',
        'assertIsNotIterable' => 'notToBeIterable',
        'assertDirectoryIsNotReadable' => 'directoryNotToBeReadable',
        'assertDirectoryIsNotWritable' => 'directoryNotToBeWritable',
        'assertDirectoryDoesNotExist' => 'directoryNotToExist',
        'assertDirectoryIsReadable' => 'directoryToBeReadable',
        'assertDirectoryIsWritable' => 'directoryToBeWritable',
        'assertDirectoryExists' => 'directoryToExist',
        'assertFileIsNotReadable' => 'fileNotToBeReadable',
        'assertFileIsNotWritable' => 'fileNotToBeWritable',
        'assertFileDoesNotExist' => 'fileNotToExist',
        'assertFileEquals' => 'fileToBeEqual',
        'assertFileEqualsCanonicalizing' => 'fileToBeEqualCanonicalizing',
        'assertFileEqualsIgnoringCase' => 'fileToBeEqualIgnoringCase',
        'assertFileIsReadable' => 'fileToBeReadable',
        'assertFileIsWritable' => 'fileToBeWritable',
        'assertFileExists' => 'fileToExist',
        'assertFileNotEquals' => 'fileToNotEqual',
        'assertFileNotEqualsCanonicalizing' => 'fileToNotEqualCanonicalizing',
        'assertFileNotEqualsIgnoringCase' => 'fileToNotEqualIgnoringCase',
        'assertIsNotClosedResource' => 'notToBeClosedResource',
        'assertIsClosedResource' => 'toBeClosedResource',
        'assertFinite' => 'toBeFinite',
        'assertInfinite' => 'toBeInfinite',
        'assertNan' => 'toBeNan',
    ];

    public function getNodeTypes(): array
    {
        return [Node\Stmt\Expression::class];
    }

    /**
     * @param Node\Stmt\Expression $node
     * @return Node\Stmt\Expression
     */
    public function refactor(Node $node)
    {
        /** @var MutatingScope $scope */
        $scope = $node->getAttribute('scope');
        Assert::assertInstanceOf(MutatingScope::class, $scope);
        $reflClass = $scope->getClassReflection();

        if (!$reflClass) {
            return $node;
        }

        if (!$reflClass->isSubclassOf(TestCase::class)) {
            return $node;
        }

        $expr = $node->expr;
        $isMethodCall = $expr instanceof Node\Expr\StaticCall || $expr instanceof Node\Expr\MethodCall;

        if (!$isMethodCall) {
            return $node;
        }

        if ($expr instanceof Node\Expr\MethodCall) {
            $callerType = $this->nodeTypeResolver->getType($expr->var);
            if (!$callerType instanceof ThisType) {
                return $node;
            }
        }

        $exprNameIdentifier = $expr->name;
        Assert::assertInstanceOf(Node\Identifier::class, $exprNameIdentifier);
        foreach (self::TWO_ARGS_METHODS_MAP as $assertion => $expectation) {
            if ($exprNameIdentifier->toString() === $assertion) {
                $expect = new Node\Expr\FuncCall(new Node\Name('expect'), [$expr->args[1]]);
                $expectationArguments = [$expr->args[0]];
                if (isset($expr->args[2])) {
                    $expectationArguments[] = $expr->args[2];
                }
                $node->expr = new Node\Expr\MethodCall($expect, new Node\Identifier($expectation), $expectationArguments);

                return $node;
            }
        }

        foreach (self::ONE_ARG_METHODS_MAP as $assertion => $expectation) {
            if ($exprNameIdentifier->toString() === $assertion) {
                $expect = new Node\Expr\FuncCall(new Node\Name('expect'), [$expr->args[0]]);
                $expectationArguments = [];
                if (isset($expr->args[1])) {
                    $expectationArguments[] = $expr->args[1];
                }

                $node->expr = new Node\Expr\MethodCall($expect, new Node\Identifier($expectation), $expectationArguments);

                return $node;
            }
        }

        return $node;
    }
}
